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

#ifndef INDOORLOCALIZATIONMOVINGMOBILITYBASE_H_
#define INDOORLOCALIZATIONMOVINGMOBILITYBASE_H_

#include "INETDefs.h"

#include "MobilityBase.h"


class INET_API IndoorLocalizationMovingMobilityBase : public MobilityBase {
protected:

    /** @brief A mobility model may decide to become stationary at any time.
     *
     * The true value disables sending self messages. */
    bool stationary;

    /** @brief The simulation time when the mobility state was last updated. */
    simtime_t lastUpdate;


    virtual int numInitStages() const {return 3;}

    void initialize(int stage);

    IndoorLocalizationMovingMobilityBase();
    virtual ~IndoorLocalizationMovingMobilityBase();
    virtual void handleSelfMessage(cMessage *msg);

    virtual void move() = 0;

    /** @brief Moves and notifies listeners. */
    virtual void moveAndUpdate();

public:
    /** @brief Returns the current position at the current simulation time. */
    virtual Coord getCurrentPosition();

    /** @brief For Indoor Localization and SpecificPositionMobility the function will move to new positon */
    virtual Coord getCurrentSpeed();


};

#endif /* INDOORLOCALIZATIONMOVINGMOBILITYBASE_H_ */
