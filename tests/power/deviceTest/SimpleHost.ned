//# Energy Framework for Omnet++, version 0.9
//#
//# Author:  Laura Marie Feeney 
//# 
//# Copyright 2009 Swedish Institute of Computer Science.  
//# 
//# This software is provided `as is' and without any express or implied
//# warranties, including, but not limited to, the implied warranties of
//# merchantability and fitness for a particular purpose.
//#
//######################################################################
// empty host to test energy framework.  see README.txt for details.
package org.mixim.tests.power.deviceTest;

import org.mixim.tests.power.utils.DeviceDutySimple;
import org.mixim.tests.power.utils.Subscriber;
import org.mixim.tests.power.PowerTestNode;

// Empty host for simple power test. 
module PowerTestHost extends PowerTestNode
{
    parameters:
        @display("bgb=190,171,$color;bgp=10,10");
    submodules:
        device: DeviceDutySimple {
            parameters:
                @display("p=45,120;b=30,25");
        }
        subscriber: Subscriber {
            @display("p=131,121");
        }
    connections:

}
