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

#ifndef INDOORLOCALIZAMAC_H_
#define INDOORLOCALIZAMAC_H_

#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "MiXiMDefs.h"
#include "BaseMacLayer.h"
#include <DroppedPacket.h>

#define Bubble(text_to_pop) findHost()->bubble(text_to_pop)

class MacPkt;
class indoorLocalizaMacPkt;

class MIXIM_API indoorLocalizaMac : public BaseMacLayer
{
  private:
    /** @brief Copy constructor is not allowed.
     */
    indoorLocalizaMac(const indoorLocalizaMac&);
    /** @brief Assignment operator is not allowed.
     */
    indoorLocalizaMac& operator=(const indoorLocalizaMac&);

  public:
    indoorLocalizaMac()
        : BaseMacLayer()
        , nbPacketsSent(0)
        , start_receiver(NULL), start_transmitter(NULL), data_tx_over(NULL), time_out(NULL), send_ack_packet(NULL), ready_to_send(NULL), wake_up(NULL)
        , macQueue(), distanceQueue()
        , macState(INIT)
        , nicId(-1)
        , queueLength(0)
        , numNodes(0)
        , timeReceived(0), timeSent(0)
        , lastDataPktSrcAddr(), lastDataPktDestAddr()
        , animation(false)
        , slotDuration(0), bitrate(0), checkInterval(0), txPower(0)
        , useMacAcks(0)
        , stats(false)
    {}
    virtual ~indoorLocalizaMac();

    /** @brief Initialization of the module and some variables*/
    virtual void initialize(int);

    /** @brief Delete all dynamically allocated objects of the module*/
    virtual void finish();

    /** @brief Handle messages from lower layer */
    virtual void handleLowerMsg(cMessage*);

    /** @brief Handle messages from upper layer */
    virtual void handleUpperMsg(cMessage*);

    /** @brief Handle self messages such as timers */
    virtual void handleSelfMsg(cMessage*);

    /** @brief Handle control messages from lower layer */
    virtual void handleLowerControl(cMessage *msg);

  protected:
    typedef std::list<indoorMacPkt_ptr_t> MacQueue;

    /** @brief A queue to store packets from upper layer in case another
    packet is still waiting for transmission.*/
    MacQueue macQueue;
    std::list<simtime_t> distanceQueue;

    /** @name Different tracked statistics.*/
    /*@{*/
    long nbTxDataPackets;
    /*@}*/

    enum States {
        INIT,   //0

        Tx_SENDING,
        Tx_WAIT_DATA_OVER,
        Tx_WAIT_N_ACKs,

        Rx_RECEIVING,
        Rx_WAIT_ACK_OVER,
        Rx_SENDING_ACK,

        Rx_SLEEP,
        Rx_WAKE_UP
      };
    /** @brief The current state of the protocol */
    States macState;

    /** @brief Types of messages (self messages and packets) the node can
     * process **/
    enum TYPES {
        // packet types
        COLLISION = 100,
        DATA_PACKET,
        ACK_PACKET,

        // self message types
        START_RECEIVER = 150,
        START_TRANSMITTER,
        READY_TO_SEND,
        TIME_OUT,
        SEND_ACK_PACKET,
        DATA_TX_OVER,
        WAKE_UP
    };

    // messages used in the FSM
    cMessage *data_tx_over;

    cMessage* start_receiver;
    cMessage* start_transmitter;
    cMessage* ready_to_send;
    cMessage* send_ack_packet;

    cMessage* time_out;
    cMessage* wake_up;

    unsigned int numNodes;
    int nicId;
    int nodeId;
    int dataPeriod;
    double ack_time_out; //default
    simtime_t timeReceived;
    simtime_t timeSent;
    LAddress::L2Type lastDataPktSrcAddr, lastDataPktDestAddr;

    /* Statistic that we want to collect */

    /** @brief Number of packets this node sends */
    long nbPacketsSent;

    /** @brief The maximum length of the queue */
    unsigned int queueLength;

    bool animation;
    /** @brief The duration of the slot in secs. */
    double slotDuration;
    /** @brief The bitrate of transmission */
    double bitrate;
    /** @brief The duration of CCA */
    double checkInterval;
    /** @brief Transmission power of the node */
    double txPower;
    /** @brief Use MAC level acks or not */
    bool useMacAcks;
    /** @brief Maximum transmission attempts per data packet, when ACKs are
     * used */
    int maxTxAttempts;
    /** @brief Gather stats at the end of the simulation */
    bool stats;

    /** @brief Possible colors of the node for animation */
    enum BMAC_COLORS {
        GREEN = 1,
        BLUE = 2,
        RED = 3,
        BLACK = 4,
        YELLOW = 5
    };

    /** @brief Internal function to change the color of the node */
    void changeDisplayColor(BMAC_COLORS color);

    /** @brief Internal function to send the first packet in the queue */
    void sendDataPacket();

    /** @brief Internal function to send an ACK */
    void sendMacAck();

    /** @brief Internal function to attach a signal to the packet */
    void attachSignal(indoorMacPkt_ptr_t macPkt);

    /** @brief Internal function to add a new packet from upper to the queue */
    bool addToQueue(cMessage * msg);

    /** @brief Internal function to add a new packet from upper to the queue */
    simtime_t calDistanceToSrc(indoorMacPkt_ptr_t pkt);

};

#endif /* INDOORLOCALIZAMAC_H_ */
