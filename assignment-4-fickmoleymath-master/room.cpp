/**************************************
 * Filename: room.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains implementation of
 * the room class
 * Input: headers
 * Output: room implementation
**************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

/**************************************
 * Function: room
 * Description: default costructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
**************************************/

Room::Room(){
	//constructs information of the room
	whichEvent = 0;
	adventurer = false;
}

/**************************************
 * Function: getWhichEvent;
 * Description: returns the correlated integer
 * in order to use in moves
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data returned
**************************************/

int Room::getWhichEvent(){
	return whichEvent;
}

/**************************************
 * Function: setWhichEvent
 * Description: sets the new event
 * Parameters: integer
 * Pre-Conditions: cant be greater that 5,
 * less than 0
 * Post-Conditions: data set
**************************************/

void Room::setWhichEvent(int newWhichEvent){
	whichEvent = newWhichEvent;
}

/**************************************
 * Function: getAdventurer
 * Description: gets a room locations
 * boolean of the adventurer location
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
**************************************/

bool Room::getAdventurer(){
	return adventurer;
}

/**************************************
 * Function: setAdventurer
 * Description: sets the boolean of the
 * adventurer location
 * Parameters: boolean
 * Pre-Conditions: must be a 1 or 0
 * Post-Conditions: adventurer manipulated
**************************************/

void Room::setAdventurer(bool newAdventurer){
	adventurer = newAdventurer;
}

/**************************************
 * Function: setEvent
 * Description: sets the events in game
 * for the room
 * Parameters: integer
 * Pre-Conditions: must be 0-5
 * Post-Conditions: constructs dynamic data
**************************************/

void Room::setEvent(int newEvent){
	//will set the polymorphed clas objectively.
	//if it doesnt have an item use the base class
	switch(newEvent){
		case 2:
			events = new Wumpus;
			break;
		case 3:
			events = new Gold;
			break;
		case 4:
			events = new Pit;
			break;
		case 5:
			events = new Bats;
			break;
		default:
			events = new Event;
			break;
	}
}

/**************************************
 * Function: getEvent
 * Description: retrieves event data
 * from the specific event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
**************************************/

string Room::getEvent(){
	return events->getPercept();
}

/**************************************
 * Function: getEntrance
 * Description: retrieves encounter data
 * from the specific event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
**************************************/

string Room::getEntrance(){
	return events->getEncounter();
}

/**************************************
 * Function:~Room
 * Description: destructs data
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data destructed
**************************************/

Room::~Room(){
	delete [] events;
}
