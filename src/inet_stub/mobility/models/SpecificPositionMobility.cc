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

#include "SpecificPositionMobility.h"
#include <fstream>

Define_Module(SpecificPositionMobility);

SpecificPositionMobility::SpecificPositionMobility() {
    // TODO Auto-generated constructor stub

    indexOfNextPosition = 0;
    listOfPositions.clear();
}

void SpecificPositionMobility::initialize(int stage)
{
    IndoorLocalizationMovingMobilityBase::initialize(stage);
    EV << "initializing SpecificPositionMobility stage " << stage << endl;
    if (stage == 0)
    {
        const char* fileName = par("fileName");

        std::ifstream in(fileName, std::ios::in);

        if (in.fail())
            throw cRuntimeError("Cannot open file '%s'", fileName);

        std::string line;
        while (std::getline(in, line))
        {
            //EV <<"Position: " <<line <<endl;
            addPostitionToList(line);
        }
    }
}

void SpecificPositionMobility::addPostitionToList(std::string inputString) {
    inputString.append(" ");
    std::string delimiter = " ";
    int dimension = 0;
    int oldPosOfDelimiter = 0;        //find(delimiter, position to start to find);
    int newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);
    Coord newPosition;
    while (newPosOfDelimiter > 0) {
                                       //substr(pos, len);
        std::string token = inputString.substr(oldPosOfDelimiter, newPosOfDelimiter - oldPosOfDelimiter);
        double value = std::stod(token);

        switch (dimension) {
        case 0:
            newPosition.x = value;
            break;
        case 1:
            newPosition.y = value;
            break;
        case 2:
            newPosition.z = value;
            break;
        default:
            EV <<"Something wrong!";
            break;
        }
        dimension += 1;
        oldPosOfDelimiter = newPosOfDelimiter + 1;
        newPosOfDelimiter = inputString.find(delimiter, oldPosOfDelimiter);
    }
    listOfPositions.push_back(newPosition);
}

void SpecificPositionMobility::initializePosition()
{
    move();
}

void SpecificPositionMobility::move()
{
    Coord newPosition = listOfPositions.front();
    listOfPositions.pop_front();
    lastPosition = newPosition;
    listOfPositions.push_back(lastPosition);
}


