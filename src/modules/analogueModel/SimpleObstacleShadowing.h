#ifndef SIMPLEOBSTACLEFADING_H_
#define SIMPLEOBSTACLEFADING_H_

#include "AnalogueModel.h"
#include "Mapping.h"
#include "BaseWorldUtility.h"
#include "ObstacleControl.h"
#include <Move.h>
#include <Signal_.h>
#include <MiximAirFrame.h>

#include <cstdlib>

/**
 * @brief Basic implementation of a SimpleObstacleShadowing that uses
 * SimplePathlossConstMapping (that is subclassed from SimpleConstMapping) as attenuation-Mapping.
 *
 * @ingroup analogueModels
 */
class SimpleObstacleShadowing : public AnalogueModel
{
protected:

	/** @brief reference to global ObstacleControl instance */
	ObstacleControl& obstacleControl;

    /** @brief carrier frequency needed for calculation */
    double carrierFrequency;

	/** @brief Information needed about the playground */
	const bool useTorus;

	/** @brief The size of the playground.*/
	const Coord& playgroundSize;

	/** @brief Whether debug messages should be displayed. */
	bool debug;

public:
	/**
	 * @brief Initializes the analogue model. myMove and playgroundSize
	 * need to be valid as long as this instance exists.
	 *
	 * The constructor needs some specific knowledge in order to create
	 * its mapping properly:
	 *
	 * @param carrierFrequency the carrier frequency
	 * @param myMove a pointer to the hosts move pattern
	 * @param useTorus information about the playground the host is moving in
	 * @param playgroundSize information about the playground the host is moving in
	 * @param debug display debug messages?
	 */

	SimpleObstacleShadowing(ObstacleControl& obstacleControl, double carrierFrequency, bool useTorus, const Coord& playgroundSize, bool debug);

	/**
	 * @brief Filters a specified Signal by adding an attenuation
	 * over time to the Signal.
	 */
	virtual void filterSignal(MiximAirFrame *frame, const Coord& sendersPos, const Coord& receiverPos);
};

#endif /*PATHLOSSMODEL_H_*/
