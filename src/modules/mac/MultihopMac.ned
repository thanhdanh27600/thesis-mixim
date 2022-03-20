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

package org.mixim.modules.mac;

import org.mixim.base.modules.BaseMacLayer;

simple MultihopMac extends BaseMacLayer
{
    parameters:
		@class(MultihopMac);
        // debug switch
        bool debug = default(false);
        //collect statistics?
        bool stats = default(true);

		// BMAC specific parameters
		// how long is one slot?
		double slotDuration @unit(s) = default(1s);
		
		// how long is the check interval (CCA)?
		double checkInterval @unit(s) = default(0.01s);
		
		// size of the MAC queue (maximum number of packets in Tx buffer)
        int queueLength = default(20);
        
        // should we animate the nodes with colors depending on their state or 
        // not?
        bool animation = default(true);
        
        // bit rate 
        double bitrate @unit(bps) = default(19200 bps);
        
        //tx power [mW]
        double txPower @unit(mW) = default(50 mW);
          
        //should mac send and expect acknowledgments?
        bool useMACAcks = default(false);
        // maximum number of frame retransmission
        // only used when usage of MAC acks is enabled
        int macMaxFrameRetries = default(3);        
}