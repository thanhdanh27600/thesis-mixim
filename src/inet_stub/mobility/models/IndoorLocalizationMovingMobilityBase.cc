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

#include "IndoorLocalizationMovingMobilityBase.h"

IndoorLocalizationMovingMobilityBase::IndoorLocalizationMovingMobilityBase() {
    // TODO Auto-generated constructor stub
    stationary = false;
    lastPosition = Coord::ZERO;
    lastUpdate = 0;
}

IndoorLocalizationMovingMobilityBase::~IndoorLocalizationMovingMobilityBase() {
    // TODO Auto-generated destructor stub

}

void IndoorLocalizationMovingMobilityBase::handleSelfMessage(cMessage *msg) {
    //do notthing because we wont schedule anything
}

void IndoorLocalizationMovingMobilityBase::initialize(int stage) {
    MobilityBase::initialize(stage);
    EV << "initializing IndoorLocalizationMovingMobilityBase stage " << stage << endl;
    if (stage == 0) {
        //moveTimer = new cMessage("move");
        //updateInterval = par("updateInterval");
    }
    else if (stage == 2) {
        lastUpdate = simTime();
        //scheduleUpdate();
    }
}

Coord IndoorLocalizationMovingMobilityBase::getCurrentPosition() {
    return this->lastPosition;
}

Coord IndoorLocalizationMovingMobilityBase::getCurrentSpeed() {
    //maybe we will update later but up until now we dont need the speed for this kind of mobility
    moveAndUpdate();
    return this->lastPosition;
}

void IndoorLocalizationMovingMobilityBase::moveAndUpdate() {
    if (!stationary) move();
    lastUpdate = simTime();
    emitMobilityStateChangedSignal();
    updateVisualRepresentation();
}
