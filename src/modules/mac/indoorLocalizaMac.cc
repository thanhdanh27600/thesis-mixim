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

#include "indoorLocalizaMac.h"

#include <cassert>
#include <string>

#include "FWMath.h"
#include "MacToPhyControlInfo.h"
#include "BaseArp.h"
#include "BaseConnectionManager.h"
#include "PhyUtils.h"
#include "MacPkt_m.h"
#include "MacToPhyInterface.h"

#include "indoorLocalizaMacPkt_m.h"

Define_Module(indoorLocalizaMac)

void indoorLocalizaMac::initialize(int stage) {
    BaseMacLayer::initialize(stage);

    if (stage == 0) {
        BaseLayer::catDroppedPacketSignal.initialize();

        queueLength = hasPar("queueLength") ? par("queueLength") : 10;
        animation = hasPar("animation") ? par("animation") : true;
        slotDuration = hasPar("slotDuration") ? par("slotDuration") : 1.;
        bitrate = hasPar("bitrate") ? par("bitrate") : 15360.;
        headerLength = hasPar("headerLength") ? par("headerLength") : 10.;
        checkInterval = hasPar("checkInterval") ? par("checkInterval") : 0.1;
        txPower = hasPar("txPower") ? par("txPower") : 50.;
        useMacAcks = hasPar("useMACAcks") ? par("useMACAcks") : true;
        maxTxAttempts = hasPar("maxTxAttempts") ? par("maxTxAttempts") : 2;
        numNodes = hasPar("numNodes") ? par("numNodes") : 3;
        stats = hasPar("stats") ? par("stats") : true;

        //Declare the node ID for a node
        nodeId = static_cast<int>(findHost()->getAncestorPar("nodeId"));

        debugEV << "State 0 at indoor localization MAC layer: \n";

        debugEV << "Node ID is: " << nodeId << endl;

        debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate
                       << endl;

        macState = INIT;

        nicId = getNic()->getId();
        WATCH(macState);
    } else if (stage == 1) {

        start_receiver = new cMessage("start_receiver");
        start_receiver->setKind(START_RECEIVER);

        start_transmitter = new cMessage("start_transmitter");
        start_transmitter->setKind(START_TRANSMITTER);

        time_out = new cMessage("time_out");
        time_out->setKind(TIME_OUT);

        data_tx_over = new cMessage("data_tx_over");
        data_tx_over->setKind(DATA_TX_OVER);

        ready_to_send = new cMessage("ready_to_send");
        ready_to_send->setKind(READY_TO_SEND);

        send_ack_packet = new cMessage("send_ack_packet");
        send_ack_packet->setKind(SEND_ACK_PACKET);

        wake_up = new cMessage("wake_up");
        wake_up->setKind(WAKE_UP);

        debugEV << "State 1 at indoor localization MAC layer: \n";

        debugEV << "Node ID is: " << nodeId << endl;

        debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate
                       << endl;

        if (nodeId == 0) {
            scheduleAt(0.5, start_transmitter);
        } else {
            scheduleAt(0.2, start_receiver);
        }

    }
}

indoorLocalizaMac::~indoorLocalizaMac() {
    MacQueue::iterator it;
    for (it = macQueue.begin(); it != macQueue.end(); ++it) {
        delete (*it);
    }
    macQueue.clear();
}

void indoorLocalizaMac::finish() {
    BaseMacLayer::finish();

    cancelAndDelete(start_receiver);
    cancelAndDelete(start_transmitter);
    cancelAndDelete(ready_to_send);
    cancelAndDelete(data_tx_over);
    cancelAndDelete(send_ack_packet);
    cancelAndDelete(time_out);

    // record stats
    if (stats) {
        recordScalar("nbPacketsSent", nbPacketsSent);
    }
}

void indoorLocalizaMac::handleUpperMsg(cMessage *msg) {
    //handle message from upper layer, up until now we dont receive messages from upper layer.

//    bool pktAdded = addToQueue(msg);
//    if (!pktAdded)
//        return;
    //debugEV << "New packet arrived, but queue is FULL, so new packet is" " deleted\n";
    msg->setName("MAC ERROR");
    msg->setKind(PACKET_DROPPED);
    sendControlUp(msg);
    //droppedPacket.setReason(DroppedPacket::QUEUE);
}

void indoorLocalizaMac::handleSelfMsg(cMessage *msg) {
    switch (macState) {
    case INIT:
        if (msg->getKind() == START_TRANSMITTER) {
            scheduleAt(simTime() + 0.1, ready_to_send);
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            macState = Tx_SENDING;

        } else if (msg->getKind() == START_RECEIVER) {
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            macState = Rx_RECEIVING;

        }
        break;

    case Tx_SENDING:
        if (msg->getKind() == READY_TO_SEND) {
            sendDataPacket();
            macState = Tx_WAIT_DATA_OVER;
        }
        break;

    case Tx_WAIT_DATA_OVER:
        if (msg->getKind() == DATA_TX_OVER) {
            simtime_t duration = numNodes * 1;
            scheduleAt(simTime() + duration + 1, time_out);

            //debugEV << "****Tx: Data packet is sent!\n";
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            macState = Tx_WAIT_N_ACKs;

        }
        break;

    case Tx_WAIT_N_ACKs:
        if (msg->getKind() == ACK_PACKET) {
//                cancelEvent(time_out);
//                scheduleAt(simTime() + 5, ready_to_send);

            //debugEV <<"****Tx: Ack packet is received!\n";
            indoorMacPkt_ptr_t pkt = dynamic_cast<indoorMacPkt_ptr_t>(msg);
            if (pkt != NULL) {
                macQueue.push_back(pkt);
                debugEV <<"Queue length " <<macQueue.size() <<"/" <<(numNodes - 1) <<endl;
                distanceQueue.push_back(calDistanceToSrc(pkt));
            } else {
                Bubble("Damn! shhieet");
            }

            if (macQueue.size() == (numNodes - 1)) {
                cancelEvent(time_out);
                scheduleAt(simTime() + 1, ready_to_send);
                debugEV << "Get distance done with total " <<macQueue.size() <<" masters" <<endl;
                changeDisplayColor(GREEN);
                phy->setRadioState(MiximRadio::TX);
                macState = Tx_SENDING;
                while (macQueue.size() != 0) {
                    delete macQueue.front();
                    macQueue.pop_front();
                    //you can get distance from this node to all masters from here, below queue.
                    // But notice the distance is currently stored at simtime_t data type not data double.
                    distanceQueue.pop_front();
                }
                macQueue.clear();
            }
            //delete pkt;
        }

        if (msg->getKind() == TIME_OUT) {
            scheduleAt(simTime(), ready_to_send);

            //debugEV << "****Tx: Timeout for ack packet!\n";
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            macState = Tx_SENDING;
        }
        break;

    case Rx_RECEIVING:
        if (msg->getKind() == DATA_PACKET) {

            //debugEV <<"****Rx: Data packet is received!\n";
            indoorMacPkt_ptr_t pkt = dynamic_cast<indoorMacPkt_ptr_t>(msg);
            lastDataPktSrcAddr = pkt->getSrcAddr();
//            debugEV << "From node with MAC address " << lastDataPktSrcAddr <<endl;
//            debugEV << "create time default: " << pkt->getCreationTime() <<endl;
//            debugEV << "create time from new class: " << pkt->getTimeSent() <<endl;
//            debugEV << "sending time: " << pkt->getSendingTime() <<endl;
//            debugEV << "arrival time: " << pkt->getArrivalTime() <<endl;

            timeSent = pkt->getTimeSent();
            timeReceived = simTime();

            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            macState = Rx_SENDING_ACK;

            //ack_time_out = numNodes * (pkt->getTimeSent() - pkt->getArrivalTime());
            simtime_t duration = (nodeId - 1) * (timeReceived - timeSent) * 2;
            //debugEV <<"**** Duration: " <<duration <<endl;
            scheduleAt(simTime() + nodeId * 1, send_ack_packet);
            delete pkt;
        }
        break;

    case Rx_SENDING_ACK:
        if (msg->getKind() == SEND_ACK_PACKET) {
            sendMacAck();
            macState = Rx_WAIT_ACK_OVER;
        }
        break;

    case Rx_WAIT_ACK_OVER:
        if (msg->getKind() == DATA_TX_OVER) {
            //debugEV <<"****Rx: Ack packet is sent!\n";
            simtime_t duration = (nodeId - 1) * (timeReceived - timeSent) * 2;
            scheduleAt(simTime() + numNodes - nodeId, wake_up);
            changeDisplayColor(BLACK);
            phy->setRadioState(MiximRadio::SLEEP);
            macState = Rx_SLEEP;
        }
        break;

    case Rx_SLEEP:
        if (msg->getKind() == WAKE_UP) {
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            macState = Rx_RECEIVING;
        }
        break;

        break;
        opp_error("Undefined event of type %d in state %d (Radio state %d)!",
                msg->getKind(), macState, phy->getRadioState());
    }
}

void indoorLocalizaMac::handleLowerMsg(cMessage *msg) {
    // simply pass the massage as self message, to be processed by the FSM.
    handleSelfMsg(msg);
}

void indoorLocalizaMac::handleLowerControl(cMessage *msg) {
    if (msg->getKind() == MacToPhyInterface::TX_OVER) {
        scheduleAt(simTime(), data_tx_over);
    } else if (msg->getKind() == COLLISION) {
        debugEV << "****Rx: We have collision on this channel!!!\n";
        Bubble("Collision!!!");
    }
    // Radio switching (to RX or TX) ir over, ignore switching to SLEEP.
    else if (msg->getKind() == MacToPhyInterface::RADIO_SWITCHING_OVER) {

    } else {
        debugEV << "control message with wrong kind -- deleting\n";
    }
    delete msg;
}

void indoorLocalizaMac::sendDataPacket() {
    nbPacketsSent++;

    indoorMacPkt_ptr_t pkt = new indoorLocalizaMacPkt("Data");
    pkt->setKind(DATA_PACKET);
    pkt->setSrcAddr(myMacAddr);
    pkt->setTimeSent(simTime());
    pkt->setBitLength(128); //bit length of ack packet and data packet must equal to calculate the distance.

    attachSignal(pkt);
    sendDown(pkt);
}

void indoorLocalizaMac::sendMacAck() {
    indoorMacPkt_ptr_t ack = new indoorLocalizaMacPkt("Ack");

    //notice here, it is useful, we will need to implement these addresses later.
    ack->setSrcAddr(myMacAddr);
    ack->setDestAddr(lastDataPktDestAddr);
    ack->setTimeSent(timeSent);
    ack->setTimeReceived(timeReceived);
    ack->setKind(ACK_PACKET);
    ack->setBitLength(128); //bit length of ack packet and data packet must equal to calculate the distance.

    //attach signal and send down
    attachSignal(ack);
    sendDown(ack);
}

bool indoorLocalizaMac::addToQueue(cMessage *msg) {
    return false;
}

void indoorLocalizaMac::attachSignal(indoorMacPkt_ptr_t macPkt) {
    //calc signal duration
    simtime_t duration = macPkt->getBitLength() / bitrate;
    //create and initialize control info with new signal
    setDownControlInfo(macPkt,
            createSignal(simTime(), duration, txPower, bitrate));
}

void indoorLocalizaMac::changeDisplayColor(BMAC_COLORS color) {
    if (!animation)
        return;
    cDisplayString& dispStr = findHost()->getDisplayString();

    if (color == GREEN)
        dispStr.setTagArg("b", 3, "green");

    if (color == BLUE)
        dispStr.setTagArg("b", 3, "blue");

    if (color == RED)
        dispStr.setTagArg("b", 3, "red");

    if (color == BLACK)
        dispStr.setTagArg("b", 3, "black");

    if (color == YELLOW)
        dispStr.setTagArg("b", 3, "yellow");
}

simtime_t indoorLocalizaMac::calDistanceToSrc(indoorMacPkt_ptr_t pkt) {
    //need to test ~~
    //debugEV << "From node:" << pkt->getSrcAddr() << " send at " << pkt->getTimeSent() << " | received at " << pkt->getTimeReceived() << endl;

    double speed = SPEED_OF_LIGHT;
    simtime_t processingSignalTime = pkt->getBitLength() / bitrate;
    simtime_t deltaTime = pkt->getTimeReceived() - processingSignalTime -  pkt->getTimeSent();
    simtime_t distance = speed * deltaTime;
    debugEV <<"Distance to node " <<pkt->getSrcAddr() <<" is " <<distance <<endl;
    return 0.0;
}
