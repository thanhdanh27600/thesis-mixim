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
#include "MultihopMacPkt_m.h"
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

        //Declare the node ID for a node
        nodeId = static_cast<int>(findHost()->getAncestorPar("nodeId"));

        std::string fileName = "gatewaysandpaths";
        readGatewayAndPath(fileName);
        this->isGateway = checkThisNodeIsGateway();

        if (this->isGateway) {
            fillPathGroups();
            createMapPathGroupToNodeId();
            debugEV << "Node ID is: " << nodeId <<" Gateway" << endl;
        }
        /*else {
            findPreviousAndNextNode();
            debugEV << "Node ID is: " << nodeId <<" Previous: " <<this->previousNodeId << " Next: " <<this->nextNodeId << endl;
        }*/

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

    if (stats){
//        debugEV << "Total packets delayed to reach last node" << metric.latency.getCount() << endl;
//        debugEV << "Total packet collision" << metric.collision.getCount() << endl;
//
//        metric.latency.recordAs("Packets Delay Stats");
//        metric.collision.recordAs("Packets Collision  Stats");
    }
}

void MultihopMac::handleUpperMsg(cMessage *msg)
{
//  This function is to handle message from Application layer and put it into the queue, but now we dont need this.

//    bool pktAdded = addToQueue(msg);
//    if (!pktAdded) return;

}

void MultihopMac::sendMacAck()
{
    macpkt_ptr_t ack = new MacPkt("ACK");
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
                changeDisplayColor(BLUE);
                phy->setRadioState(MiximRadio::SLEEP);
                macState = GW_IDLE;
            }

            if(msg->getKind() == START_SENSOR_NODE) {
                EV <<"Start sensor node" <<endl;
                changeDisplayColor(BLACK);
                phy->setRadioState(MiximRadio::RX);
                macState = SN_RECEIVING;
            }

            break;
        case GW_IDLE:
            if(msg->getKind() == SEND_DATA_PACKET) {
                //sendDataPacket();
                scheduleAt(simTime(), ready_to_send);
                //changeDisplayColor(GREEN);
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

                assert(static_cast<cPacket*>(msg));
                macpkt_ptr_t mac = static_cast<macpkt_ptr_t>(msg);
                const LAddress::L2Type& dest = mac->getDestAddr();
                const LAddress::L2Type& src  = mac->getSrcAddr();

                if ((dest == myMacAddr) && (src == LAddress::L2Type(this->nextNodeId))) {
                    cancelEvent(time_out);
                    debugEV << "****Gateway: Receive a right ACK!!!" << endl;

                    changeDisplayColor(BLUE);
                    phy->setRadioState(MiximRadio::SLEEP);
                    macState = GW_IDLE;
                    scheduleAt(simTime() + dataPeriod, send_data_packet);

                }
                delete msg;
                msg = NULL;
                mac = NULL;

                return;
            }

            if(msg->getKind() == TIME_OUT) {
                changeDisplayColor(BLUE);
                phy->setRadioState(MiximRadio::TX);
                scheduleAt(simTime() + 0.1, ready_to_send);
                macState = GW_SENDING;
                return;
            }
            break;

        case SN_RECEIVING:
            if(msg->getKind() == DATA_PACKET) { //receive

                assert(static_cast<cPacket*>(msg));
                multihopMacPkt_ptr_t mac = static_cast<multihopMacPkt_ptr_t>(msg);
                const LAddress::L2Type& dest = mac->getDestAddr();
                //const LAddress::L2Type& src  = mac->getSrcAddr();

                if (dest == myMacAddr) {

                    EV <<"RECEIVE | SRC: " <<mac->getSrcAddr() <<" DEST: " <<mac->getDestAddr() <<endl;
                    debugEV << "****Sensor node: Data package is received" << endl;
                    this->lastDataPacketReceived = mac;
                    if (mac->getIsRouting()) {
                        findPreviousAndNextNode(mac->getPath());
                        debugEV <<"this is routing packet with size of " <<mac->getPath().size() <<endl;
                    } else {
                        debugEV <<"this is normal packet with size of " <<mac->getPath().size() <<endl;
                    }
                    debugEV << "Node ID is: " << nodeId <<" Previous: " <<this->previousNodeId << " Next: " <<this->nextNodeId << endl;

                    if (this->nextNodeId != -1) { //middle node
                        //sendUp(decapsMsg(mac);
                        metric.latency.record(mac->getId());
                        if (mac->getSignal() == 0) {
                            Bubble("0");
                            changeDisplayColor(BLACK);
                        } else {
                            Bubble("1");
                            changeDisplayColor(YELLOW);
                        }
                        phy->setRadioState(MiximRadio::TX);
                        scheduleAt(simTime(), ready_to_send);
                        macState = SN_SENDING_DATA;
                    } else { //final node
                        //sendUp(decapsMsg(mac));
                        metric.latency.record(1000.0);
                        if (mac->getSignal() == 0) {
                            Bubble("0");
                            changeDisplayColor(BLACK);
                        } else {
                            Bubble("1");
                            changeDisplayColor(YELLOW);
                        }
                        //changeDisplayColor(GREEN);
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
                debugEV << "****Sensor node: Data packet is forwarded!!!" << endl;
                //changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                scheduleAt(simTime() + 5, time_out); //modify later just wait for the number of nodes in its path.
                macState = SN_WAITING_ACK;
                debugEV << "****Sensor node: Change to WAITING _ACK state!!!" << endl;
            }
            break;
        case SN_WAITING_ACK:
            if (msg->getKind() == ACK_PACKET) {
                debugEV <<"****Sensor node: Receive ACK packet!" <<endl;

                assert(static_cast<cPacket*>(msg));
                macpkt_ptr_t mac = static_cast<macpkt_ptr_t>(msg);
                const LAddress::L2Type& dest = mac->getDestAddr();
                const LAddress::L2Type& src  = mac->getSrcAddr();

                if ((dest == myMacAddr) && (src == LAddress::L2Type(this->nextNodeId))) {
                    //sendUp(decapsMsg(mac));
                    //changeDisplayColor(GREEN);
                    cancelEvent(time_out);
                    txAttempts = 0;

                    phy->setRadioState(MiximRadio::TX);
                    scheduleAt(simTime(), ready_to_send);
                    macState = SN_SENDING_ACK;

                }
                delete msg;
                msg = NULL;
                mac = NULL;
                return;
            }
            if (msg->getKind() == TIME_OUT) {
                txAttempts += 1;
                if (txAttempts == maxTxAttempts) {
                    txAttempts = 0;
                    phy->setRadioState(MiximRadio::RX);
                    macState = SN_RECEIVING;
                }
                phy->setRadioState(MiximRadio::TX);
                scheduleAt(simTime() + 0.1, ready_to_send);
                macState = SN_SENDING_DATA;
                return;
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
                debugEV <<"****Sensor node: ACK packet is already sent!" <<endl;
                //changeDisplayColor(RED);
                phy->setRadioState(MiximRadio::RX);
                macState = SN_RECEIVING;
                //reset information
                this->lastDataPacketReceived = NULL;
                //this->previousNodeId = - 1;
                //this->nextNodeId = -1;
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
        multihopMacPkt_ptr_t pkt = new MultihopMacPkt("STREET LIGHT");
        pkt->setKind(DATA_PACKET);
        pkt->setSignal(intrand(2));
        pkt->setSrcAddr(myMacAddr);

        size_t l = pathGroups.size();
        //choose random 1 of paths that this gateway control, and map the path group to the first sensor node ID.
        int r = intrand(l);
        LAddress::L2Type dest = LAddress::L2Type(mapPathGroupToNodeId[pathGroups[r]]);
        pkt->setDestAddr(dest);
        this->nextNodeId = mapPathGroupToNodeId[pathGroups[r]];
        int isRoutingPacket = intrand(2);
        pkt->setIsRouting(this->firstRouting);

        if (this->firstRouting) {
            Bubble("1");
        } else {
            Bubble("0");
        }

        if (this->firstRouting) {
            pkt->setPath(getOnePathByGroup(pathGroups[r]));
        } else {
            pkt->setPath(std::vector<int>());
        }
        this->firstRouting = false;
        // bit length = queue size * 8
        pkt->setBitLength((pkt->getPath().size() + 1) * 8);
        attachSignal(pkt);
        sendDown(pkt);
    } else {
        //if this is a sensor the only choose is forward the data packet to the next node.

        assert(lastDataPacketReceived);
        multihopMacPkt_ptr_t pkt = new MultihopMacPkt(*lastDataPacketReceived);
        pkt->setDestAddr(LAddress::L2Type(this->nextNodeId));
        pkt->setSrcAddr(myMacAddr);

        if (pkt->getIsRouting()) {
            pkt->getPath().erase(pkt->getPath().begin());
            debugEV <<"Size after: " << pkt->getPath().size() <<endl;
            //traverse(pkt->getPath());
        } else {
            debugEV <<"Size of normal packet: " << pkt->getPath().size() <<endl;
            traverse(pkt->getPath());
        }
        // bit length = queue size * 8
        pkt->setBitLength((pkt->getPath().size() + 1) * 8);
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
        metric.collision.record(1.0);
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

void MultihopMac::readGatewayAndPath(std::string fileName)
{

    std::ifstream in(fileName, std::ios::in);

    if (in.fail())
        throw cRuntimeError("Cannot open file\n");

    std::string line;

    std::getline(in, line);

    // parse souce node
    std::stringstream s_stream(line);
    while (s_stream.good())
    {
        std::string substr;
        std::getline(s_stream, substr, ',');
        gatewayList.push_back(stod(substr));
    }

    /* print all source node */

    for (int i = 0; i < gatewayList.size(); i++)
    {
        std::cout << gatewayList.at(i) << std::endl;
    }

    while (std::getline(in, line))
    {
        getPathFromString(line);
    }
}

void MultihopMac::getPathFromString(std::string inputString)
{
    std::vector<int> curRelayNodeList;

    inputString.append(",");
    std::string delimiter = ",";

    int count = 0;
    int oldPosOfDelimiter = 0; // find(delimiter, position to start to find);
    int newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);

    while (newPosOfDelimiter > 0)
    {
        std::string token = inputString.substr(oldPosOfDelimiter, newPosOfDelimiter - oldPosOfDelimiter);

        if (token != "NAN")
        {
            bool validNode = true;
            int nodeId = std::stoi(token);

            if (!count) // check if first token is always source node
                validNode = std::find(gatewayList.begin(), gatewayList.end(), nodeId) != gatewayList.end();

            if (validNode)
                curRelayNodeList.push_back(nodeId);

            oldPosOfDelimiter = newPosOfDelimiter + 1;
            newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);
            count += 1;
        }
    }

    /* print all relay node */

    // for (int i = 0; i < curRelayNodeList.size(); i++)
    // {
    //     std::cout << curRelayNodeList.at(i) << std::endl;
    // }

    paths.push_back(curRelayNodeList);
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

void MultihopMac::findPreviousAndNextNode(const std::vector<int> path) {
    this->previousNodeId = path[0];
    if (path.size() > 2) this->nextNodeId = path[2];
    else this->nextNodeId = -1;
}

std::vector<int> MultihopMac::getOnePathByGroup(int groupIndex)
{
    return this->paths[groupIndex];
}

void MultihopMac::traverse(std::vector<int> inputVector) {
    std::vector<int>::iterator it;
    if (inputVector.size() > 0) {
        for (it = inputVector.begin(); it < inputVector.end(); it++) debugEV <<(*it) <<" ";
        EV <<endl;
    }
}
