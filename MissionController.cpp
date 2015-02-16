/*
 * MissionController.cpp
 *
 *  Created on: 16 Feb 2015
 *      Author: Charlie
 */

#include "MissionController.h"

#include "Log.h"

void MissionController::MissionController(void) {

	TRACE("[MC] Constructor.");

	//Initialise our internal variables to match the state of the game field

	//Game rules define the number and type of eggs
	eggsRemaining[EGG_WHITE] = 2;
	eggsRemaining[EGG_BROWN] = 2;
	eggsRemaining[EGG_MULTI] = 1;
	eggsRemaining[EGG_INDETERMINATE] = 0;

	//At the start, we have not deposited any eggs
	eggsPlaced = 0;

	TRACE("[MC] Created.");

}

void MissionController::RunMission(void) {

	INFO("[MC] Starting mission.");

	//While the game is still active
	while (totalEggsRemaining() > 0)
	{
		//Navigate to the nearest occupied egg collection point

		//Pick up the egg

		//Mark the current collection point as unoccupied

		//Identify the egg using the sensor(s)
		EGGTYPE e = EGG_WHITE; //TODO identify the type

		//Sanity check the type of egg
		if(eggsRemaining[e] <= 0) {

			ERR("We must have mis-identified an egg! Identified as " <<
					e << " but there are none left in play.");

			//TODO what course of action should be taken?

			//If there is only one egg remaining, it is logical to assume that it is this egg
			if(totalEggsRemaining() == 1) {

			}
			//If there are multiple eggs in play, we should re-scan until a sensible answer is received.
			else {

			}
		}

		//Signal the type using the LEDs
		signalEggType(e);

		//Navigate to the correct dropoff point

		//Deposit the egg in the egg cup

		//Update the total number of eggs remaining
		eggsRemaining[e]--;
		eggsPlaced++; //This is technically redundant - it should always be equal to (5 - totalEggsRemaining())...

	}

	INFO("[MC] Mission complete.");
}


