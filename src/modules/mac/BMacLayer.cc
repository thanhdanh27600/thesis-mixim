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

#include "BMacLayer.h"

#include <cassert>

#include "FWMath.h"
#include "MacToPhyControlInfo.h"
#include "BaseArp.h"
#include "BaseConnectionManager.h"
#include "PhyUtils.h"
#include "MacPkt_m.h"
#include "MacToPhyInterface.h"

#define Bubble(text_to_pop) findHost()->bubble(text_to_pop)

Define_Module( BMacLayer )

/**
 * Initialize method of BMacLayer. Init all parameters, schedule timers.
 */
void BMacLayer::initialize(int stage)
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

		debugEV << "Node ID is: " << nodeId << endl;

		debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate << endl;

		stats = par("stats");
		nbTxDataPackets = 0;
		nbTxPreambles = 0;
		nbRxDataPackets = 0;
		nbRxPreambles = 0;
		nbMissedAcks = 0;
		nbRecvdAcks=0;
		nbDroppedDataPackets=0;
		nbTxAcks=0;

		txAttempts = 0;
		lastDataPktDestAddr = LAddress::L2BROADCAST;
		lastDataPktSrcAddr  = LAddress::L2BROADCAST;

		macState = INIT;

		// init the dropped packet info
		droppedPacket.setReason(DroppedPacket::NONE);
		nicId = getNic()->getId();
		WATCH(macState);
	}
	else if(stage == 1) {

		//data_timeout = new cMessage("data_timeout");
		//data_timeout->setKind(BMAC_DATA_TIMEOUT);
		//data_timeout->setSchedulingPriority(100);


	    wakeup = new cMessage("wake_up");
	    wakeup->setKind(WAKE_UP);

		start_receiver= new cMessage("start_receiver");
        start_receiver->setKind(START_RECEIVER);

        start_transmitter = new cMessage("start_transmitter");
        start_transmitter->setKind(START_TRANSMITTER);



        time_out = new cMessage("time_out");
        time_out->setKind(TIME_OUT);

        data_tx_over = new cMessage("data_tx_over");
        data_tx_over->setKind(DATA_TX_OVER);

        ready_to_send = new cMessage("ready_to_send");
        ready_to_send->setKind(READY_TO_SEND);

        debugEV << "Node ID is: " << nodeId << endl;

        debugEV << "headerLength: " << headerLength << ", bitrate: " << bitrate << endl;

		if(nodeId == 0){
		    scheduleAt(0.2, start_receiver);
		} else {
		    scheduleAt(0.5, start_transmitter);
		    dataPeriod = 5;
		}

	}
}

BMacLayer::~BMacLayer()
{


	cancelAndDelete(data_tx_over);


	MacQueue::iterator it;
	for(it = macQueue.begin(); it != macQueue.end(); ++it)
	{
		delete (*it);
	}
	macQueue.clear();
}

void BMacLayer::finish()
{
    BaseMacLayer::finish();

    // record stats
    if (stats)
    {
    	recordScalar("nbTxDataPackets", nbTxDataPackets);
    	recordScalar("nbTxPreambles", nbTxPreambles);
    	recordScalar("nbRxDataPackets", nbRxDataPackets);
    	recordScalar("nbRxPreambles", nbRxPreambles);
    	recordScalar("nbMissedAcks", nbMissedAcks);
    	recordScalar("nbRecvdAcks", nbRecvdAcks);
    	recordScalar("nbTxAcks", nbTxAcks);
    	recordScalar("nbDroppedDataPackets", nbDroppedDataPackets);
    	//recordScalar("timeSleep", timeSleep);
    	//recordScalar("timeRX", timeRX);
    	//recordScalar("timeTX", timeTX);
    }
}

/**
 * Check whether the queue is not full: if yes, print a warning and drop the
 * packet. Then initiate sending of the packet, if the node is sleeping. Do
 * nothing, if node is working.
 */
void BMacLayer::handleUpperMsg(cMessage *msg)
{
	bool pktAdded = addToQueue(msg);
	if (!pktAdded)
		return;
	// force wakeup now
//	if (wakeup->isScheduled() && (macState == SLEEP))
//	{
//		cancelEvent(wakeup);
//		scheduleAt(simTime() + dblrand()*0.1f, wakeup);
//	}
}

/**
 * Send one short preamble packet immediately.
 */
void BMacLayer::sendPreamble()
{
//	macpkt_ptr_t preamble = new MacPkt();
//	preamble->setSrcAddr(myMacAddr);
//	preamble->setDestAddr(LAddress::L2BROADCAST);
//	preamble->setKind(BMAC_PREAMBLE);
//	preamble->setBitLength(headerLength);
//
//	//attach signal and send down
//	attachSignal(preamble);
//	sendDown(preamble);
//	nbTxPreambles++;
}

/**
 * Send one short preamble packet immediately.
 */
void BMacLayer::sendMacAck()
{
	macpkt_ptr_t ack = new MacPkt();
	//ack->setSrcAddr(myMacAddr);
	//ack->setDestAddr(lastDataPktSrcAddr);
	ack->setKind(ACK_PACKAGE);
	ack->setBitLength(64);

	//attach signal and send down
	attachSignal(ack);
	sendDown(ack);
	nbTxAcks++;
	//endSimulation();
}

/**
 * Handle own messages:
 * BMAC_WAKEUP: wake up the node, check the channel for some time.
 * BMAC_CHECK_CHANNEL: if the channel is free, check whether there is something
 * in the queue and switch the radio to TX. When switched to TX, the node will
 * start sending preambles for a full slot duration. If the channel is busy,
 * stay awake to receive message. Schedule a timeout to handle false alarms.
 * BMAC_SEND_PREAMBLES: sending of preambles over. Next time the data packet
 * will be send out (single one).
 * BMAC_TIMEOUT_DATA: timeout the node after a false busy channel alarm. Go
 * back to sleep.
 */
void BMacLayer::handleSelfMsg(cMessage *msg)
{
	switch (macState)
	{

    case INIT:
        if(msg->getKind() == START_TRANSMITTER){
            scheduleAt(simTime() + 0.1, ready_to_send);
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            macState = Tx_SENDING;
            return;
        }

        if(msg->getKind() == START_RECEIVER){
            macState = Rx_RECEIVING;
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            return;
        }

        break;
	case Tx_SENDING:
        if(msg->getKind() == READY_TO_SEND){
            sendDataPacket();
            macState = Tx_WAIT_DATA_OVER;

            return;
        }
        break;
    case Tx_WAIT_DATA_OVER:
        if(msg->getKind() == DATA_TX_OVER){
            debugEV << "****Tx: Data package is already sent!!!" << endl;
            debugEV << "****Tx: Waiting for ACK package..." << endl;

            macState = Tx_WAIT_ACK;
            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);
            scheduleAt(simTime() + 0.1, time_out);

            return;
        }
        break;
    case Tx_WAIT_ACK:
        if(msg->getKind() == ACK_PACKAGE){
            cancelEvent(time_out);
            debugEV << "****Tx: Receive an ACK!!!" << endl;

            changeDisplayColor(BLACK);
            phy->setRadioState(MiximRadio::SLEEP);
            scheduleAt(simTime() + dataPeriod, wakeup);
            macState = Tx_SLEEP;
            return;
        }

        if(msg->getKind() == TIME_OUT){
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            scheduleAt(simTime() + 0.1, ready_to_send);
            macState = Tx_SENDING;
            return;
        }
        break;
    case Tx_SLEEP:
        if(msg->getKind() == WAKE_UP){

            scheduleAt(simTime() + 0.1, ready_to_send);
            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);

            macState = Tx_SENDING;
            return;
        }
        break;
    case Rx_RECEIVING:
        if(msg->getKind() == DATA_PACKAGE) { //receive and ack
            debugEV << "****Rx: Data package is received!!!" << endl;
            debugEV << "****Rx: ACK package is sending..." << endl;

            changeDisplayColor(GREEN);
            phy->setRadioState(MiximRadio::TX);
            sendMacAck();
            macState = Rx_WAIT_ACK_OVER;

            return;
        }
        break;
    case Rx_WAIT_ACK_OVER:
        if(msg->getKind() == DATA_TX_OVER){
            debugEV << "****Rx: ACK package is sent!!!" << endl;

            changeDisplayColor(RED);
            phy->setRadioState(MiximRadio::RX);

            macState = Rx_RECEIVING;
            return;
        }
        break;
	}
	opp_error("Undefined event of type %d in state %d (Radio state %d)!",
			  msg->getKind(), macState, phy->getRadioState());
}


/**
 * Handle BMAC preambles and received data packets.
 */
void BMacLayer::handleLowerMsg(cMessage *msg)
{
	// simply pass the massage as self message, to be processed by the FSM.
	handleSelfMsg(msg);
}

void BMacLayer::sendDataPacket()
{
	nbTxDataPackets++;
	//macpkt_ptr_t pkt = macQueue.front()->dup();
	macpkt_ptr_t pkt = new MacPkt();
	pkt->setKind(DATA_PACKAGE);

	pkt->setBitLength(128);
	attachSignal(pkt);
	//lastDataPktDestAddr = pkt->getDestAddr();

	sendDown(pkt);
}

/**
 * Handle transmission over messages: either send another preambles or the data
 * packet itself.
 */
void BMacLayer::handleLowerControl(cMessage *msg)
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
//    	if ((macState == SEND_PREAMBLE) && (phy->getRadioState() == MiximRadio::TX))
//    	{
//    		scheduleAt(simTime(), send_preamble);
//    	}
//    	if ((macState == SEND_ACK) && (phy->getRadioState() == MiximRadio::TX))
//    	{
//    		scheduleAt(simTime(), send_ack);
//    	}
//    	// we were waiting for acks, but none came. we switched to TX and now
//    	// need to resend data
//    	if ((macState == SEND_DATA) && (phy->getRadioState() == MiximRadio::TX))
//    	{
//    		scheduleAt(simTime(), resend_data);
//    	}

    }
    else {
        debugEV << "control message with wrong kind -- deleting\n";
    }
    delete msg;
}

/**
 * Encapsulates the received network-layer packet into a MacPkt and set all
 * needed header fields.
 */
bool BMacLayer::addToQueue(cMessage *msg)
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
		nbDroppedDataPackets++;

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

void BMacLayer::attachSignal(macpkt_ptr_t macPkt)
{
	//calc signal duration
	simtime_t duration = macPkt->getBitLength() / bitrate;
	//create and initialize control info with new signal
	setDownControlInfo(macPkt, createSignal(simTime(), duration, txPower, bitrate));
}

/**
 * Change the color of the node for animation purposes.
 */

void BMacLayer::changeDisplayColor(BMAC_COLORS color)
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

/*void BMacLayer::changeMacState(States newState)
{
	switch (macState)
	{
	case RX:
		timeRX += (simTime() - lastTime);
		break;
	case TX:
		timeTX += (simTime() - lastTime);
		break;
	case SLEEP:
		timeSleep += (simTime() - lastTime);
		break;
	case CCA:
		timeRX += (simTime() - lastTime);
	}
	lastTime = simTime();

	switch (newState)
	{
	case CCA:
		changeDisplayColor(GREEN);
		break;
	case TX:
		changeDisplayColor(BLUE);
		break;
	case SLEEP:
		changeDisplayColor(BLACK);
		break;
	case RX:
		changeDisplayColor(YELLOW);
		break;
	}

	macState = newState;
}*/
