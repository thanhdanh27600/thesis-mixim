//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <MultihopMac.h>

#include <cassert>

#include "FWMath.h"
#include "MacToPhyControlInfo.h"
#include "BaseArp.h"
#include "BaseConnectionManager.h"
#include "PhyUtils.h"
#include "MacPkt_m.h"
#include "MacToPhyInterface.h"

#define Bubble(text_to_pop) findHost()->bubble(text_to_pop)

Define_Module( MultihopMac )

void MultihopMac::initialize(int stage)
{
    BaseMacLayer::initialize(stage);

    if (stage == 0) {
        BaseLayer::catDroppedPacketSignal.initialize();

        queueLength   = hasPar("queueLength")   ? par("queueLength")   : 10;
        animation     = hasPar("animation")     ? par("animation")     : true;
        slotDuration  = hasPar("slotDuration")  ? par("slotDuration")  : 1.;
        bitrate       = hasPar("bitrate")       ? par("bitrate")       : 15360.;
        headerLength  = hasPar("headerLength")  ? par("headerLength")  : 10.;
        checkInterval = hasPar("checkInterval") ? par("checkInterval") : 0.1;
        txPower       = hasPar("txPower")       ? par("txPower")       : 50.;
        useMacAcks    = hasPar("useMACAcks")    ? par("useMACAcks")    : false;
        maxTxAttempts = hasPar("maxTxAttempts") ? par("maxTxAttempts") : 2;


        gatewayList = getGatewayList();
        paths = getPaths();

        //Declare the node ID for a node
        nodeId = static_cast<int>(findHost()->getAncestorPar("nodeId"));

        this->isGateway = checkThisNodeIsGateway();

        if (this->isGateway) {
            fillPathGroups();
            createMapPathGroupToNodeId();
            debugEV << "Node ID is: " << nodeId <<" Gateway" << endl;
        } else {
            findPreviousAndNextNode();
            debugEV << "Node ID is: " << nodeId <<" Previous: " <<this->previousNodeId << " Next: " <<this->nextNodeId << endl;
        }

        //debugEV << "Node ID is: " << nodeId << endl;

        //debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate << endl;

        stats = par("stats");

        txAttempts = 0;
        lastDataPktDestAddr = LAddress::L2BROADCAST;
        lastDataPktSrcAddr  = LAddress::L2BROADCAST;
        lastDataPacketReceived = NULL;

        macState = INIT;

        // init the dropped packet info
        droppedPacket.setReason(DroppedPacket::NONE);
        nicId = getNic()->getId();
        WATCH(macState);
    }
    else if(stage == 1) {
        wake_up = new cMessage("wake_up");
        wake_up->setKind(WAKE_UP);

        start_gateway = new cMessage("start_gateway");
        start_gateway->setKind(START_GATEWAY);

        start_sensor_node = new cMessage("start_sensor_node");
        start_sensor_node->setKind(START_SENSOR_NODE);

        time_out = new cMessage("time_out");
        time_out->setKind(TIME_OUT);

        data_tx_over = new cMessage("data_tx_over");
        data_tx_over->setKind(DATA_TX_OVER);

        send_data_packet = new cMessage("send_data_packet");
        send_data_packet->setKind(SEND_DATA_PACKET);

        ready_to_send = new cMessage("ready_to_send");
        ready_to_send->setKind(READY_TO_SEND);

        send_ack_packet = new cMessage("send_ack_packet");
        send_ack_packet->setKind(SEND_ACK_PACKET);

        debugEV << "Node ID is: " << nodeId <<" | Nic ID is: " <<nicId  <<" | Mac Address: " <<myMacAddr  <<endl;

        debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate << endl;

        if (this->isGateway) {
            scheduleAt(simTime() + 0.5, start_gateway);
        } else {
            scheduleAt(simTime() + 0.2, start_sensor_node);
        }
    }
}

MultihopMac::~MultihopMac()
{


    cancelAndDelete(data_tx_over);


    MacQueue::iterator it;
    for(it = macQueue.begin(); it != macQueue.end(); ++it)
    {
        delete (*it);
    }
    macQueue.clear();
}

void MultihopMac::finish()
{
    BaseMacLayer::finish();

    // record stats
    if (stats)
    {
       //if we need to record anythings
    }
}

void MultihopMac::handleUpperMsg(cMessage *msg)
{
//  This function is to handle message from Application layer and put it into the queue, but now we dont need this.

    bool pktAdded = addToQueue(msg);
    if (!pktAdded) return;

}

void MultihopMac::sendMacAck()
{
    macpkt_ptr_t ack = new MacPkt();
    ack->setSrcAddr(myMacAddr);
    ack->setDestAddr(LAddress::L2Type(this->previousNodeId));
    ack->setKind(ACK_PACKET);
    ack->setBitLength(64);

    //attach signal and send down
    attachSignal(ack);
    sendDown(ack);
    //endSimulation();
}

void MultihopMac::handleSelfMsg(cMessage *msg)
{
    switch (macState)
    {
        case INIT:
            if(msg->getKind() == START_GATEWAY) {
                EV <<"Start gateway" <<endl;
                scheduleAt(simTime(), send_data_packet);
                changeDisplayColor(BLACK);
                phy->setRadioState(MiximRadio::SLEEP);
                macState = GW_IDLE;
            }

            if(msg->getKind() == START_SENSOR_NODE) {
                EV <<"Start sensor node" <<endl;
                changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                macState = SN_RECEIVING;
            }

            break;
        case GW_IDLE:
            if(msg->getKind() == SEND_DATA_PACKET) {
                //sendDataPacket();
                scheduleAt(simTime(), ready_to_send);
                changeDisplayColor(GREEN);
                phy->setRadioState(MiximRadio::TX);
                macState = GW_SENDING;
            }
            break;
        case GW_SENDING:
            if(msg->getKind() == READY_TO_SEND) {
                sendDataPacket();
                macState = GW_WAIT_DATA_OVER;
            }
            break;
        case GW_WAIT_DATA_OVER:
            if(msg->getKind() == DATA_TX_OVER) {
                debugEV << "****Gateway: Data package is already sent!!!" << endl;
                debugEV << "****Gateway: Waiting for ACK package..." << endl;

                macState = GW_WAIT_ACK;
                changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                scheduleAt(simTime() + 2, time_out); //modify later just wait for the number of nodes in its path.
            }
            break;
        case GW_WAIT_ACK:
            if(msg->getKind() == ACK_PACKET) {
                cancelEvent(time_out);
                debugEV << "****Gateway: Receive an ACK!!!" << endl;

                changeDisplayColor(BLACK);
                phy->setRadioState(MiximRadio::TX);
                macState = GW_IDLE;
                scheduleAt(simTime() + dataPeriod, send_data_packet);
            }

            if(msg->getKind() == TIME_OUT) {
                changeDisplayColor(GREEN);
                phy->setRadioState(MiximRadio::TX);
                scheduleAt(simTime() + 0.1, ready_to_send);
                macState = GW_SENDING;
            }
            break;

        case SN_RECEIVING:
            if(msg->getKind() == DATA_PACKET) { //receive
                debugEV << "****Sensor node: Data package is received" << endl;

                assert(static_cast<cPacket*>(msg));
                macpkt_ptr_t mac = static_cast<macpkt_ptr_t>(msg);
                this->lastDataPacketReceived = mac;

                const LAddress::L2Type& dest = mac->getDestAddr();
                const LAddress::L2Type& src  = mac->getSrcAddr();

                //EV <<"RECEIVE | SRC: " <<mac->getSrcAddr() <<" DEST: " <<mac->getDestAddr() <<endl;

                if ((dest == myMacAddr) && (src == LAddress::L2Type(this->previousNodeId))) {
                    if (this->nextNodeId != -1) { //middle node
                        //sendUp(decapsMsg(mac));
                        Bubble(mac->getName());
                        changeDisplayColor(GREEN);
                        phy->setRadioState(MiximRadio::TX);
                        scheduleAt(simTime(), ready_to_send);
                        macState = SN_SENDING_DATA;
                    } else { //final node
                        //sendUp(decapsMsg(mac));
                        Bubble(mac->getName());
                        changeDisplayColor(GREEN);
                        phy->setRadioState(MiximRadio::TX);
                        scheduleAt(simTime(), ready_to_send);
                        macState = SN_SENDING_ACK;
                    }
                } else {
                    delete msg;
                    msg = NULL;
                    mac = NULL;
                }
            }
            break;
        case SN_SENDING_DATA:
            if(msg->getKind() == READY_TO_SEND) {
                debugEV << "****Sensor node: Data package is forwarding..." << endl;
                sendDataPacket();
                macState = SN_WAIT_DATA_OVER;
            }
            break;
        case SN_WAIT_DATA_OVER:
            if (msg->getKind() == DATA_TX_OVER) {
                debugEV << "****Sensor node: Data packet is forward!!!" << endl;
                changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                scheduleAt(simTime() + 2, time_out); //modify later just wait for the number of nodes in its path.
                macState = SN_WAITING_ACK;
            }
            break;
        case SN_WAITING_ACK:
            if (msg->getKind() == ACK_PACKET) {
                cancelEvent(time_out);

                assert(static_cast<cPacket*>(msg));
                macpkt_ptr_t mac = static_cast<macpkt_ptr_t>(msg);
                const LAddress::L2Type& dest = mac->getDestAddr();
                const LAddress::L2Type& src  = mac->getSrcAddr();
                this->lastDataPacketReceived = NULL;

                if ((dest == myMacAddr) && (src == LAddress::L2Type(this->nextNodeId))) {
                    //sendUp(decapsMsg(mac));
                    changeDisplayColor(GREEN);
                    phy->setRadioState(MiximRadio::TX);
                    scheduleAt(simTime(), ready_to_send);
                    macState = SN_SENDING_ACK;
                } else {
                    delete msg;
                    msg = NULL;
                    mac = NULL;
                }
            }
            break;
        case SN_SENDING_ACK:
            if (msg->getKind() == READY_TO_SEND) {
                sendMacAck();
                macState = SN_WAIT_ACK_OVER;
            }
            break;
        case SN_WAIT_ACK_OVER:
            if (msg->getKind() == DATA_TX_OVER) {
                changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                macState = SN_RECEIVING;
            }
            break;

        opp_error("Undefined event of type %d in state %d (Radio state %d)!",
                          msg->getKind(), macState, phy->getRadioState());
    }
}

void MultihopMac::handleLowerMsg(cMessage *msg)
{
    // simply pass the massage as self message, to be processed by the FSM.
    handleSelfMsg(msg);
}

void MultihopMac::sendDataPacket()
{
//    if (!macQueue.empty()) {
//        Bubble("Prepare to send!");
//        macpkt_ptr_t pkt = macQueue.front()->dup();
//        pkt->setKind(DATA_PACKET);
//
//        pkt->setBitLength(128);
//        attachSignal(pkt);
//        lastDataPktDestAddr = pkt->getDestAddr();
//        sendDown(pkt);
//    } else {
//        Bubble("Queue Empty!");
//    }

    // this will be modify later


    if (isGateway) {
        macpkt_ptr_t pkt = (intrand(2) == 0) ? new MacPkt("0") : new MacPkt("1");
        pkt->setKind(DATA_PACKET);
        pkt->setSrcAddr(myMacAddr);
        pkt->setBitLength(128);

        size_t l = pathGroups.size();
        //choose random 1 of paths that this gateway control, and map the path group to the first sensor node ID.
        LAddress::L2Type dest = LAddress::L2Type(mapPathGroupToNodeId[pathGroups[intrand(l)]]);
        pkt->setDestAddr(dest);

        attachSignal(pkt);
        sendDown(pkt);
    } else {
        //if this is a sensor the only choose is forward the data packet to the next node.
        macpkt_ptr_t pkt = new MacPkt(*lastDataPacketReceived);

        pkt->setDestAddr(LAddress::L2Type(this->nextNodeId));
        pkt->setSrcAddr(myMacAddr);

        attachSignal(pkt);
        sendDown(pkt);
    }
}

void MultihopMac::handleLowerControl(cMessage *msg)
{
    // Transmission of one packet is over
    if(msg->getKind() == MacToPhyInterface::TX_OVER) {
        scheduleAt(simTime(), data_tx_over);
    } else  if (msg->getKind() == COLLISION) {
        debugEV << "****Rx: We have collision on this channel!!!\n";
        Bubble("Collision!!!");
    }
    // Radio switching (to RX or TX) ir over, ignore switching to SLEEP.
    else if(msg->getKind() == MacToPhyInterface::RADIO_SWITCHING_OVER) {
        // we just switched to TX after CCA, so simply send the first
        // sendPremable self message
//      if ((macState == SEND_PREAMBLE) && (phy->getRadioState() == MiximRadio::TX))
//      {
//          scheduleAt(simTime(), send_preamble);
//      }
//      if ((macState == SEND_ACK) && (phy->getRadioState() == MiximRadio::TX))
//      {
//          scheduleAt(simTime(), send_ack);
//      }
//      // we were waiting for acks, but none came. we switched to TX and now
//      // need to resend data
//      if ((macState == SEND_DATA) && (phy->getRadioState() == MiximRadio::TX))
//      {
//          scheduleAt(simTime(), resend_data);
//      }

    }
    else {
        debugEV << "control message with wrong kind -- deleting\n";
    }
    delete msg;
}

bool MultihopMac::addToQueue(cMessage *msg)
{
    if (macQueue.size() >= queueLength) {
        // queue is full, message has to be deleted
        debugEV << "New packet arrived, but queue is FULL, so new packet is"
                  " deleted\n";
        msg->setName("MAC ERROR");
        msg->setKind(PACKET_DROPPED);
        sendControlUp(msg);
        droppedPacket.setReason(DroppedPacket::QUEUE);
        emit(BaseLayer::catDroppedPacketSignal, &droppedPacket);

        return false;
    }

    macpkt_ptr_t macPkt = new MacPkt(msg->getName());
    macPkt->setBitLength(headerLength);
    cObject *const cInfo = msg->removeControlInfo();
    //EV<<"CSMA received a message from upper layer, name is "
    //  << msg->getName() <<", CInfo removed, mac addr="
    //  << cInfo->getNextHopMac()<<endl;
    macPkt->setDestAddr(getUpperDestinationFromControlInfo(cInfo));
    delete cInfo;
    macPkt->setSrcAddr(myMacAddr);

    assert(static_cast<cPacket*>(msg));
    macPkt->encapsulate(static_cast<cPacket*>(msg));

    macQueue.push_back(macPkt);
    debugEV << "Max queue length: " << queueLength << ", packet put in queue"
              "\n  queue size: " << macQueue.size() << " macState: "
              << macState << endl;
    return true;
}

void MultihopMac::attachSignal(macpkt_ptr_t macPkt)
{
    //calc signal duration
    simtime_t duration = macPkt->getBitLength() / bitrate;
    //create and initialize control info with new signal
    setDownControlInfo(macPkt, createSignal(simTime(), duration, txPower, bitrate));
}

void MultihopMac::changeDisplayColor(BMAC_COLORS color)
{
    if (!animation)
        return;
    cDisplayString& dispStr = findHost()->getDisplayString();
    //b=40,40,rect,black,black,2"
    if (color == GREEN)
        dispStr.setTagArg("b", 3, "green");
        //dispStr.parse("b=40,40,rect,green,green,2");
    if (color == BLUE)
        dispStr.setTagArg("b", 3, "blue");
                //dispStr.parse("b=40,40,rect,blue,blue,2");
    if (color == RED)
        dispStr.setTagArg("b", 3, "red");
                //dispStr.parse("b=40,40,rect,red,red,2");
    if (color == BLACK)
        dispStr.setTagArg("b", 3, "black");
                //dispStr.parse("b=40,40,rect,black,black,2");
    if (color == YELLOW)
        dispStr.setTagArg("b", 3, "yellow");
                //dispStr.parse("b=40,40,rect,yellow,yellow,2");
}

bool MultihopMac::checkThisNodeIsGateway()
{
    std::vector<int>::iterator it;
    for (it = gatewayList.begin(); it < gatewayList.end(); it++) {
        //EV <<"ID: " <<*it <<endl;
        if ((*it) == this->nodeId) return true;
    }
    return false;
}


std::vector<std::vector<int>> MultihopMac::getPaths()
{
    std::vector<std::vector<int>> result;
    result.clear();

    int myArray[3][3] = {{0, 1, 2}, {0, 3, 4}, {5, 6, 7}};
    for (int i = 0; i < 3; i ++) {
        result.push_back(std::vector<int>(myArray[i], myArray[i] + sizeof(myArray[i]) / sizeof(int)));
    }
    return result;
}

std::vector<int> MultihopMac::getGatewayList()
{
    //get the gate list from .ini or from file
    int myArray[] = {0, 5}; //replace this
    std::vector<int> result = std::vector<int>(myArray, myArray + sizeof(myArray) / sizeof(int)); //replace this

    return result;
}

void MultihopMac::fillPathGroups()
{
    pathGroups.clear();

    for (size_t i = 0; i < paths.size(); i++) {
        if (paths[i].at(0) == this->nodeId) { //gateway always at index 0
            pathGroups.push_back(i);
        }
    }
}

void MultihopMac::createMapPathGroupToNodeId()
{
    mapPathGroupToNodeId.clear();

    for (size_t i = 0; i < paths.size(); i++) {
        mapPathGroupToNodeId[i] = paths[i].at(1); //the first sensor node always at index 1
    }
}

void MultihopMac::findPreviousAndNextNode() {
    for (size_t i = 0; i < paths.size(); i++) {
        for (size_t j = 1; j < paths[i].size(); j++) {
            if (paths[i].at(j) == this->nodeId) {
                if (j == paths[i].size() - 1) { //final node
                    this->previousNodeId = paths[i].at(j - 1);
                } else { //middle node
                    this->previousNodeId = paths[i].at(j - 1);
                    this->nextNodeId = paths[i].at(j + 1);
                }
            }
        }
    }
}
