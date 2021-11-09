/***************************************************************************
 * file:        BaseMacLayer.cc
 *
 * author:      Daniel Willkomm
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 ***************************************************************************
 * part of:     framework implementation developed by tkn
 * description: basic MAC layer class
 *              subclass to create your own MAC layer
 **************************************************************************/

#include "BaseMacLayer.h"

#include <cassert>
#include <sstream>

#ifdef MIXIM_INET
#include <InterfaceTableAccess.h>
#endif

#include "Mapping.h"
#include "Signal_.h"
#include "MacToPhyInterface.h"
#include "MacToNetwControlInfo.h"
#include "NetwToMacControlInfo.h"
#include "MacToPhyControlInfo.h"
#include "AddressingInterface.h"
#include "connectionManager/ConnectionManagerAccess.h"
#include "FindModule.h"
#include "MacPkt_m.h"

Define_Module(BaseMacLayer);

/**
 * First we have to initialize the module from which we derived ours,
 * in this case BaseLayer.
 *
 **/
void BaseMacLayer::initialize(int stage)
{
    BaseLayer::initialize(stage);

    if (stage == 0)
    {
        // get handle to phy layer
        if ((phy = FindModule<MacToPhyInterface*>::findSubModule(getNic())) == NULL) {
            error("Could not find a PHY module.");
        }
        headerLength = par("headerLength");
        phyHeaderLength = phy->getPhyHeaderLength();

        hasPar("coreDebug") ? coreDebug = par("coreDebug").boolValue() : coreDebug = false;
    }
    if (myMacAddr == LAddress::L2NULL) {
        // see if there is an addressing module available
        // otherwise use NIC modules id as MAC address
        AddressingInterface* addrScheme = FindModule<AddressingInterface*>::findSubModule(findHost());
        if(addrScheme) {
            myMacAddr = addrScheme->myMacAddr(this);
        } else {
            const std::string addressString = par("address").stringValue();
            if (addressString.empty() || addressString == "auto")
                myMacAddr = LAddress::L2Type(getNic()->getId());
            else
                myMacAddr = LAddress::L2Type(addressString.c_str());
            // use streaming operator for string conversion, this makes it more
            // independent from the myMacAddr type
            std::ostringstream oSS; oSS << myMacAddr;
            par("address").setStringValue(oSS.str());
        }
        registerInterface();
    }
}

void BaseMacLayer::registerInterface()
{
#ifdef MIXIM_INET
    IInterfaceTable *ift = InterfaceTableAccess().getIfExists();
    if (ift) {
        cModule* nic = getParentModule();
        InterfaceEntry *e = new InterfaceEntry(this);

        // interface name: NIC module's name without special
        // characters ([])
        char *interfaceName = new char[strlen(nic->getFullName()) + 1];
        char *d = interfaceName;
        for (const char *s = nic->getFullName(); *s; s++)
            if (isalnum(*s))
                *d++ = *s;
        *d = '\0';

        e->setName(interfaceName);
        delete[] interfaceName;

        // this MAC address must be the same as the one in BaseMacLayer
        e->setMACAddress(myMacAddr);

        // generate interface identifier for IPv6
        e->setInterfaceToken(myMacAddr.formInterfaceIdentifier());

        // MTU on 802.11 = ?
        e->setMtu(1500); // FIXME

        // capabilities
        e->setBroadcast(true);
        e->setMulticast(true);
        e->setPointToPoint(false);

        // add
        ift->addInterface(e);
    }
#endif
}

/**
 * Decapsulates the network packet from the received MacPkt
 **/
cPacket* BaseMacLayer::decapsMsg(macpkt_ptr_t msg)
{
    cPacket *m = msg->decapsulate();
    setUpControlInfo(m, msg->getSrcAddr());
    // delete the macPkt
    delete msg;
    coreEV << " message decapsulated " << endl;
    return m;
}

/**
 * Encapsulates the received NetwPkt into a MacPkt and set all needed
 * header fields.
 **/
BaseMacLayer::macpkt_ptr_t BaseMacLayer::encapsMsg(cPacket *netwPkt)
{
    macpkt_ptr_t pkt = new MacPkt(netwPkt->getName(), netwPkt->getKind());
    pkt->setBitLength(headerLength);

    // copy dest address from the Control Info attached to the network
    // message by the network layer
    cObject* cInfo = netwPkt->removeControlInfo();

    coreEV << "CInfo removed, mac addr=" << getUpperDestinationFromControlInfo(cInfo) << endl;
    pkt->setDestAddr(getUpperDestinationFromControlInfo(cInfo));

    //delete the control info
    delete cInfo;

    //set the src address to own mac address (nic module getId())
    pkt->setSrcAddr(myMacAddr);

    //encapsulate the network packet
    pkt->encapsulate(netwPkt);
    coreEV << "pkt encapsulated\n";

    return pkt;
}

/**
 * Redefine this function if you want to process messages from upper
 * layers before they are send to lower layers.
 *
 * To forward the message to lower layers after processing it please
 * use @ref sendDown. It will take care of anything needed
 **/
void BaseMacLayer::handleUpperMsg(cMessage *mac)
{
    assert(dynamic_cast<cPacket*>(mac));
    sendDown(encapsMsg(static_cast<cPacket*>(mac)));
}

/**
 * This basic implementation just forwards all message that are
 * broadcast (destAddr = L2BROADCAST) or destined for this node
 * (destAddr = nic module getId()) to the network layer
 *
 * @sa sendUp
 **/

void BaseMacLayer::handleLowerMsg(cMessage *msg)
{
    macpkt_ptr_t     mac  = static_cast<macpkt_ptr_t>(msg);
    LAddress::L2Type dest = mac->getDestAddr();
    LAddress::L2Type src  = mac->getSrcAddr();

    //only foward to upper layer if message is for me or broadcast
    if((dest == myMacAddr) || LAddress::isL2Broadcast(dest)) {
		coreEV << "message with mac addr " << src
			   << " for me (dest=" << dest
			   << ") -> forward packet to upper layer\n";
		sendUp(decapsMsg(mac));
    }
    else{
		coreEV << "message with mac addr " << src
			   << " not for me (dest=" << dest
			   << ") -> delete (my MAC="<<myMacAddr<<")\n";
		delete mac;
    }
}

void BaseMacLayer::handleLowerControl(cMessage* msg)
{
    switch (msg->getKind())
    {
        case MacToPhyInterface::TX_OVER:
            msg->setKind(TX_OVER);
            sendControlUp(msg);
            break;
        default:
            EV << "BaseMacLayer does not handle control messages of this type (name was " << msg->getName() << ")\n";
            delete msg;
            break;
    }
}

Signal* BaseMacLayer::createSignal(simtime_t_cref start, simtime_t_cref length, double power, double bitrate)
{
    simtime_t end = start + length;
    //create signal with start at current simtime and passed length
    Signal* s = new Signal(start, length);

    //create and set tx power mapping
    Mapping* txPowerMapping = createRectangleMapping(start, end, power);
    s->setTransmissionPower(txPowerMapping);

    //create and set bitrate mapping
    Mapping* bitrateMapping = createConstantMapping(start, end, bitrate);
    s->setBitrate(bitrateMapping);

    return s;
}

Mapping* BaseMacLayer::createConstantMapping(simtime_t_cref start, simtime_t_cref end, Argument::mapped_type_cref value)
{
    //create mapping over time
    Mapping* m = MappingUtils::createMapping(Argument::MappedZero, DimensionSet::timeDomain, Mapping::LINEAR);

    //set position Argument
    Argument startPos(start);

    //set mapping at position
    m->setValue(startPos, value);

    //set position Argument
    Argument endPos(end);

    //set mapping at position
    m->setValue(endPos, value);

    return m;
}

Mapping* BaseMacLayer::createRectangleMapping(simtime_t_cref start, simtime_t_cref end, Argument::mapped_type_cref value)
{
    //create mapping over time
    Mapping* m = MappingUtils::createMapping(DimensionSet::timeDomain, Mapping::LINEAR);

    //set position Argument
    Argument startPos(start);
    //set discontinuity at position
    MappingUtils::addDiscontinuity(m, startPos, Argument::MappedZero, MappingUtils::post(start), value);

    //set position Argument
    Argument endPos(end);
    //set discontinuity at position
    MappingUtils::addDiscontinuity(m, endPos, Argument::MappedZero, MappingUtils::pre(end), value);

    return m;
}

ConstMapping* BaseMacLayer::createSingleFrequencyMapping(simtime_t_cref             start,
                                                         simtime_t_cref             end,
                                                         Argument::mapped_type_cref centerFreq,
                                                         Argument::mapped_type_cref halfBandwidth,
                                                         Argument::mapped_type_cref value)
{
    Mapping* res = MappingUtils::createMapping(Argument::MappedZero, DimensionSet::timeFreqDomain, Mapping::LINEAR);

    Argument pos(DimensionSet::timeFreqDomain);

    pos.setArgValue(Dimension::frequency, centerFreq - halfBandwidth);
    pos.setTime(start);
    res->setValue(pos, value);

    pos.setTime(end);
    res->setValue(pos, value);

    pos.setArgValue(Dimension::frequency, centerFreq + halfBandwidth);
    res->setValue(pos, value);

    pos.setTime(start);
    res->setValue(pos, value);

    return res;
}

BaseConnectionManager* BaseMacLayer::getConnectionManager() const
{
    return ConnectionManagerAccess::getConnectionManager(getNic());
}

const LAddress::L2Type& BaseMacLayer::getUpperDestinationFromControlInfo(const cObject * const pCtrlInfo) const
{
    return NetwToMacControlInfo::getDestFromControlInfo(pCtrlInfo);
}

/**
 * Attaches a "control info" (MacToNetw) structure (object) to the message pMsg.
 */
cObject* BaseMacLayer::setUpControlInfo(cMessage * const pMsg, const LAddress::L2Type& pSrcAddr)
{
    return MacToNetwControlInfo::setControlInfo(pMsg, pSrcAddr);
}

/**
 * Attaches a "control info" (MacToPhy) structure (object) to the message pMsg.
 */
cObject* BaseMacLayer::setDownControlInfo(cMessage * const pMsg, Signal * const pSignal)
{
    return MacToPhyControlInfo::setControlInfo(pMsg, pSignal);
}
