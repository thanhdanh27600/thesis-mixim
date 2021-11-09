// Energy Framework for Omnet++, version 0.9
//
// Author:  Laura Marie Feeney 
// 
// Copyright 2009 Swedish Institute of Computer Science.  
// 
// This software is provided `as is' and without any express or implied
// warranties, including, but not limited to, the implied warranties of
// merchantability and fitness for a particular purpose.
//
//*********************************************************************
package org.mixim.tests.power.deviceTest;

import org.mixim.tests.power.PowerTestNetwork;

// Fundamental test case, used for basic unit testing. The Host includes
// only the Battery and the DutyCycleSimple device.
network PowerDeviceTestNet extends PowerTestNetwork
{
    parameters:

    submodules:
        host[numHosts]: PowerTestHost {
            parameters:
                @display("p=50,50;b=30,25,rect");
        }
    connections allowunconnected:
}
