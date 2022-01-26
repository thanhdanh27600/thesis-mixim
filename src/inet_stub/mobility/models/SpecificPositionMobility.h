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

#ifndef SPECIFICPOSITIONMOBILITY_H_
#define SPECIFICPOSITIONMOBILITY_H_

#include "INETDefs.h"
#include <string.h>
#include "IndoorLocalizationMovingMobilityBase.h"


class INET_API SpecificPositionMobility : public IndoorLocalizationMovingMobilityBase {
protected:

    /** @brief index of next position in the file*/
    long indexOfNextPosition;

    /** @brief list of all positions that we will move in order*/
    std::list<Coord> listOfPositions;

    /** @brief Initializes mobility model parameters.*/
    virtual void initialize(int stage);

    /** @brief Initializes the position according to the mobility model. */
    virtual void initializePosition();

    /** @brief Move the host according to the current simulation time. */
    virtual void move();

    void addPostitionToList(std::string inputString);

public:
    SpecificPositionMobility();
};

#endif /* SPECIFICPOSITIONMOBILITY_H_ */
