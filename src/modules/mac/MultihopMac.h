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

#ifndef MULTIHOPMAC_H_
#define MULTIHOPMAC_H_

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <fstream>

#include "MiXiMDefs.h"
#include "BaseMacLayer.h"
#include <DroppedPacket.h>

class MacPkt;
typedef struct Metric {
  /** @brief Number of packet to reack the last node */
  cOutVector latency;
  /** @brief  Number of collision occurs*/
  cOutVector collision;
};

class MIXIM_API MultihopMac : public BaseMacLayer
{
  private:
    /** @brief Copy constructor is not allowed.
     */
    MultihopMac(const MultihopMac&);
    /** @brief Assignment operator is not allowed.
     */
    MultihopMac& operator=(const MultihopMac&);

  public:
    MultihopMac()
          : BaseMacLayer()
          , macQueue()
          , macState(INIT)
          , send_data_packet(NULL), wake_up(NULL)
          , lastDataPktSrcAddr()
          , lastDataPktDestAddr()
          , txAttempts(0)
          , nicId(-1)
          , queueLength(0)
          , animation(false)
          , slotDuration(0), bitrate(0), checkInterval(0), txPower(0)
          , useMacAcks(0)
          , maxTxAttempts(0)
          , stats(false)
          ,metric()
     {}

     virtual ~MultihopMac();

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
      typedef std::list<macpkt_ptr_t> MacQueue;
      /** @brief A queue to store packets from upper layer in case another
      packet is still waiting for transmission.*/
      MacQueue macQueue;

      /** brief List of paths */
      std::vector<std::vector<int>> paths;

      /** @brief List contains node ID of gateway */
      std::vector<int> gatewayList;

      /** @brief List of path that this gateway (if it is a gateway) */
      std::vector<int> pathGroups;

      /** @brief This will let the gateway to know what node to send when it want to send to a specific path */
      std::map<int, int> mapPathGroupToNodeId;

      enum States {
          INIT,   //0

          GW_SENDING,

          GW_WAIT_DATA_OVER,
          GW_SLEEP,
          GW_IDLE,
          GW_WAKE_UP,
          GW_WAIT_ACK,

          SN_RECEIVING,
          SN_SENDING_DATA,
          SN_WAIT_DATA_OVER,
          SN_WAITING_ACK,
          SN_SENDING_ACK,
          SN_WAIT_ACK_OVER,
      };

      States macState;

      enum TYPES {
          // packet types
          COLLISION = 100,
          DATA_PACKET,
          ACK_PACKET,
          // self message types

          START_GATEWAY = 150,
          START_SENSOR_NODE,
          SEND_DATA_PACKET,
          TIME_OUT,
          SEND_ACK_PACKET,
          READY_TO_SEND,
          DATA_TX_OVER,
          WAKE_UP
      };

      cMessage *wake_up;
      cMessage *data_tx_over;

      //STOP and WAIT message
      cMessage* start_gateway;
      cMessage* start_sensor_node;
      cMessage* send_data_packet;

      cMessage* send_ack_packet;
      cMessage* ready_to_send;
      cMessage* time_out;



      /** @name Help variables for the acknowledgment process. */
      /*@{*/
      LAddress::L2Type lastDataPktSrcAddr;
      LAddress::L2Type lastDataPktDestAddr;
      int              txAttempts = 0;
      /*@}*/

      /** @brief Inspect reasons for dropped packets */
      DroppedPacket droppedPacket;

      /** @brief publish dropped packets nic wide */
      int nicId;
      int nodeId;
      double dataPeriod = 5;
      int ack_time_out = 0.2;

      /** @brief The maximum length of the queue */
      unsigned int queueLength;
      /** @brief Animate (colorize) the nodes.
       *
       * The color of the node reflects its basic status (not the exact state!)
       * BLACK - node is sleeping
       * GREEN - node is receiving
       * YELLOW - node is sending
       */
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

      /** @brief Previous node ID of this node*/
      int previousNodeId = -1;
      /** @brief Next node ID of this node */
      int nextNodeId = -1;

      /** @brief If this node is a gateway */
      bool isGateway = false;

      /** @brief The last data packet recevied */
      multihopMacPkt_ptr_t lastDataPacketReceived = NULL;

      /** @brief Possible colors of the node for animation */
      enum BMAC_COLORS {
          GREEN = 1,
          BLUE = 2,
          RED = 3,
          BLACK = 4,
          YELLOW = 5
      };

      Metric metric;

      /** @brief Internal function to change the color of the node */
      void changeDisplayColor(BMAC_COLORS color);

      /** @brief Internal function to send the first packet in the queue */
      void sendDataPacket();

      /** @brief Internal function to send an ACK */
      void sendMacAck();

      /** @brief Internal function to attach a signal to the packet */
      void attachSignal(macpkt_ptr_t macPkt);

      /** @brief Internal function to add a new packet from upper to the queue */
      bool addToQueue(cMessage * msg);

      /** @brief Check if a node is a gateway with its node ID */
      bool checkThisNodeIsGateway();

      /** @brief Get list of gateways and paths from file */
      void readGatewayAndPath(std::string fileName);
      /** @brief Get list of and paths from a line */
      void getPathFromString(std::string inputString);

      /** @brief To fill pathGroups List */
      void fillPathGroups();

      /** @brief Create the mapPathGroupToNodeId */
      void createMapPathGroupToNodeId();

      /** @brief Find the previous and next node of this node */
      void findPreviousAndNextNode(const std::vector<int> path);

      /** @brief Get one path by the group index */
      std::vector<int> getOnePathByGroup(int groupIndex);

      void traverse(std::vector<int> inputVector);
};

#endif /* MULTIHOPMAC_H_ */
