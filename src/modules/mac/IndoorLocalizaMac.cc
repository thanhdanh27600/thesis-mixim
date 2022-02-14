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

#include "IndoorLocalizaMac.h"

#include <cassert>
#include <string>
#include <fstream>

#include "FWMath.h"
#include "MacToPhyControlInfo.h"
#include "BaseArp.h"
#include "BaseConnectionManager.h"
#include "PhyUtils.h"
#include "MacPkt_m.h"
#include "MacToPhyInterface.h"
#include "IndoorLocalizaMacPkt_m.h"
#include "Triangulation.h"

Define_Module(IndoorLocalizaMac)

void IndoorLocalizaMac::initialize(int stage) {
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
        numNodes = hasPar("numNodes") ? par("numNodes") : 4;
        numReceivers = hasPar("numReceivers") ? par("numReceivers") : 3;
        numTransmitters = hasPar("numTransmitters") ? par("numTransmitters") : 1;
        stats = hasPar("stats") ? par("stats") : true;
        debug = hasPar("debug") ? par("debug") : false;
        errorLocalizeStats.setName("Error Stats");
        areaLocalizeStats.setName("Area Stats");

        //Declare the node ID for a node
        nodeId = static_cast<int>(findHost()->getAncestorPar("nodeId"));

        debugEV << "State 0 at indoor localization MAC layer: \n";

        debugEV << "Node ID is: " << nodeId << endl;

        debugEV << "Initial position: " << (hasPar("initialX") ? par("initialX") : 999.0) << endl;

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

        if (nodeId >= numReceivers) {
            scheduleAt(0.0 + numReceivers*(numNodes - 1 - nodeId), start_transmitter);
        } else {
            scheduleAt(0.0, start_receiver);
        }

    }
}

IndoorLocalizaMac::~IndoorLocalizaMac() {
    MacQueue::iterator it;
    for (it = macQueue.begin(); it != macQueue.end(); ++it) {
        delete (*it);
    }
    macQueue.clear();
}

void IndoorLocalizaMac::finish() {
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

        debugEV << "Error Localize Min:    " << errorLocalizeStats.getMin() << endl;
        debugEV << "Error Localize Max:    " << errorLocalizeStats.getMax() << endl;
        debugEV << "Error Localize Mean:   " << errorLocalizeStats.getMean() << endl;
        debugEV << "Error Localize Std.: " << errorLocalizeStats.getStddev() << endl;

        errorLocalizeStats.recordAs("Error Localize Stats");
    }
}

void IndoorLocalizaMac::handleUpperMsg(cMessage *msg) {
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

void IndoorLocalizaMac::handleSelfMsg(cMessage *msg) {
    switch (macState) {
    case INIT:
        if (msg->getKind() == START_TRANSMITTER) {
            errorListOfM1.clear();
            errorListOfM2.clear();
            errorListOfM3.clear();

            getErrorFromFile(0);
            getErrorFromFile(1);
            getErrorFromFile(2);
            EV << "list 1 size " <<errorListOfM1.size() <<endl;
            EV << "list 2 size " <<errorListOfM2.size() <<endl;
            EV << "list 3 size " <<errorListOfM3.size() <<endl;

            scheduleAt(simTime(), ready_to_send);
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
            simtime_t duration = numReceivers * 1 - 0.5;
            scheduleAt(simTime() + duration, time_out);

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
                debugEV <<"Queue length " <<macQueue.size() <<"/" <<(numReceivers) <<endl;
                simtime_t dist = calDistanceToSrc(pkt);
                simtime_t dist_error = normal(0, 1);
                distanceQueue.push_back(dist + dist_error);
            } else {
                Bubble("Damn! shhieet");
            }

            if (macQueue.size() == (unsigned int)numReceivers) {
                cancelEvent(time_out);
                scheduleAt(simTime() + numReceivers * (numTransmitters - 1) + 0.5, wake_up);
                debugEV << "Get position of node " <<nodeId << " done with total " <<macQueue.size() <<" masters" <<endl;
                changeDisplayColor(BLACK);
                phy->setRadioState(MiximRadio::SLEEP);
                macState = Tx_SLEEP;
                indoorMacPkt_ptr_t temp_pkt;
                double *Radius = new double[3];
                while (macQueue.size() != 0) {
                    temp_pkt = macQueue.front();
                    //debugEV <<"Distance to node " <<temp_pkt->getSrcAddr() <<" is " <<distanceQueue.front().dbl() <<endl;
                    *Radius++ = distanceQueue.front().dbl();
                    delete temp_pkt;
                    macQueue.pop_front();
                    distanceQueue.pop_front();
                    //you can get distance from this node to all masters from here, above queue.
                    // But notice the distance is currently stored at simtime_t data type not data double.
                }
                handleTriangulation(------Radius);

                //move to new position
                getConnectionManager()->getNics().find(getNic()->getId())->second->chAccess->getMobilityModule()->getCurrentSpeed();

                macQueue.clear();
                distanceQueue.clear();
            }
        }
        if (msg->getKind() == TIME_OUT) {
            indoorMacPkt_ptr_t temp_pkt;
            while (macQueue.size() != 0) {
                temp_pkt = macQueue.front();
                //debugEV <<"Distance to node " <<pkt->getSrcAddr() <<" is " <<distanceQueue.front() <<endl;
                delete temp_pkt;
                macQueue.pop_front();
                distanceQueue.pop_front();
            }
            macQueue.clear();
            distanceQueue.clear();

            scheduleAt(simTime(), ready_to_send);

            //debugEV << "****Tx: Timeout for ack packet!\n";
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            macState = Tx_SENDING;
        }
        break;
    case Tx_SLEEP:
        if (msg->getKind() == WAKE_UP) {
            //move to new position
            //getConnectionManager()->getNics().find(getNic()->getId())->second->chAccess->getMobilityModule()->getCurrentSpeed();
            scheduleAt(simTime(), ready_to_send);
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
            //simtime_t duration = (nodeId - 1) * (timeReceived - timeSent) * 2;
            //scheduleAt(simTime() + numNodes - 1 - nodeId, wake_up);
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            macState = Rx_RECEIVING;
        }
        break;

    case Rx_SLEEP:
        if (msg->getKind() == WAKE_UP) {
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            macState = Rx_RECEIVING;
        }
        break;
        opp_error("Undefined event of type %d in state %d (Radio state %d)!",
                msg->getKind(), macState, phy->getRadioState());
    }
}

void IndoorLocalizaMac::handleLowerMsg(cMessage *msg) {
    // simply pass the massage as self message, to be processed by the FSM.
    handleSelfMsg(msg);
}

void IndoorLocalizaMac::handleLowerControl(cMessage *msg) {
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

void IndoorLocalizaMac::sendDataPacket() {
    nbPacketsSent++;

    indoorMacPkt_ptr_t pkt = new IndoorLocalizaMacPkt("Data");
    pkt->setKind(DATA_PACKET);
    pkt->setSrcAddr(myMacAddr);
    pkt->setTimeSent(simTime());
    pkt->setBitLength(128); //bit length of ack packet and data packet must equal to calculate the distance.

    attachSignal(pkt);
    sendDown(pkt);
}

void IndoorLocalizaMac::sendMacAck() {
    indoorMacPkt_ptr_t ack = new IndoorLocalizaMacPkt("Ack");

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

bool IndoorLocalizaMac::addToQueue(cMessage *msg) {
    return false;
}

void IndoorLocalizaMac::attachSignal(indoorMacPkt_ptr_t macPkt) {
    //calc signal duration
    simtime_t duration = macPkt->getBitLength() / bitrate;
    //create and initialize control info with new signal
    setDownControlInfo(macPkt,
            createSignal(simTime(), duration, txPower, bitrate));
}

void IndoorLocalizaMac::changeDisplayColor(BMAC_COLORS color) {
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

simtime_t IndoorLocalizaMac::calDistanceToSrc(indoorMacPkt_ptr_t pkt) {

    //debugEV << "From node:" << pkt->getSrcAddr() << " send at " << pkt->getTimeSent() << " | received at " << pkt->getTimeReceived() << endl;

    double speed = SPEED_OF_LIGHT;
    simtime_t processingSignalTime = pkt->getBitLength() / bitrate;
    simtime_t deltaTime = pkt->getTimeReceived() - processingSignalTime - pkt->getTimeSent();
    simtime_t distance = speed * deltaTime;
    simtime_t error;
    if (pkt->getSrcAddr().getInt() == 0) {
        EV << "list 1 size " <<errorListOfM1.size();
        int index = intrand(errorListOfM1.size());
        EV <<" with index: " <<index <<endl;
        error = simtime_t(errorListOfM1.at(index));
    } else if (pkt->getSrcAddr().getInt() == 1) {
        EV << "list 2 size " <<errorListOfM2.size();
        int index = intrand(errorListOfM2.size());
        EV <<" " <<index <<endl;
        error = simtime_t(errorListOfM2.at(index));
    } else if (pkt->getSrcAddr().getInt() == 2) {
        EV << "list 3 size " <<errorListOfM3.size();
        int index = intrand(errorListOfM3.size());
        EV <<" " <<index <<endl;
        error = simtime_t(errorListOfM3.at(index));
    } else {
        debugEV <<"MAC address error at calDistanceToSrc" <<endl;
    }
    debugEV <<"Distance to node " <<pkt->getSrcAddr() <<" is " <<distance <<"with error: " <<error <<endl;
    return distance + error;
}

double IndoorLocalizaMac::getErrorFromFile(int master) {
    std::string fileName = "error/Master";
    fileName = fileName + std::to_string(master+1);
    fileName = fileName + "_error.csv";

    std::ifstream in(fileName, std::ios::in);

    if (in.fail())
        throw cRuntimeError("Cannot open file\n");

    std::string line;
    std::getline(in, line);
    while (std::getline(in, line))
    {
        //EV <<"Data: " <<line <<endl;
        getErrorFromString(line, master);
    }
}

void IndoorLocalizaMac::getErrorFromString(std::string inputString, int master) {
    inputString.append(",");
    std::string delimiter = ",";
    int slave = 1;
    int count = 1;
    int oldPosOfDelimiter = 0;        //find(delimiter, position to start to find);
    int newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);

    while (newPosOfDelimiter > 0) {
                                       //substr(pos, len);
        std::string token = inputString.substr(oldPosOfDelimiter, newPosOfDelimiter - oldPosOfDelimiter);
        if ((count == 3 + slave) && (token != "NAN")) {
            double value = std::stod(token);
            switch (master) {
            case 0:
                errorListOfM1.push_back(value);
                break;
            case 1:
                errorListOfM2.push_back(value);
                break;
            case 2:
                errorListOfM3.push_back(value);
                break;
            default:
                EV <<"Something wrong!";
                break;
            }
        }
        oldPosOfDelimiter = newPosOfDelimiter + 1;
        newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);
        count += 1;
    }
}

void IndoorLocalizaMac::handleTriangulation(double* Radius){
    int gateIndex = 0;
    BaseConnectionManager *base = getConnectionManager();
    const NicEntry::GateList &gateList = base->getGateList(getNic()->getId());
    NicEntry::GateList::const_iterator i = gateList.begin();
    Coord *masterCenter = new Coord[gateList.size()];
    for (; i != gateList.end(); ++i)
    {
        masterCenter[gateIndex++] = i->first->chAccess->getMobilityModule()->getCurrentPosition(/*sStart*/);
    }
    Coord Actual = base->getNics().find(getNic()->getId())->second->chAccess->getMobilityModule()->getCurrentPosition(/*sStart*/);
    Triangulation *triangulation = new Triangulation(masterCenter, Radius);
    debugEV << "Start predicting with 3 centers: " << masterCenter[0] << masterCenter[1] << masterCenter[2] << endl;
    debugEV << "With 3 radii: " << Radius[0] << Radius[1] << Radius[2] << endl;

    Coord Predicted = triangulation->predict();

    double errorDistance = Actual.distance(Predicted);

    debugEV << "Area of Triangle:" << triangulation->area << endl;
    debugEV << "Predicted:" << Predicted << endl;
    debugEV << "Actual:" << Actual << endl;
    debugEV << "Error: " << errorDistance << endl;

    errorLocalizeStats.collect(errorDistance);
    errorLocalizeVector.record(errorDistance);
    areaLocalizeStats.collect(triangulation->area);
    areaLocalizeVector.record(triangulation->area);
}
