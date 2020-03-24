/******************************************
 * Filename: bats.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains the class functionality
 * for the event class
 * Input: headers
 * Output: class construction, destruction
******************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"

using namespace std;

/*****************************************
 * Function: Event
 * Description: Constructor (default) for 
 * the event class
 * Parameters: none
 * Pre-Conditions: none
 * Post Conditions: constructs data
*****************************************/

Event::Event(){
	//percept here is unutilized, held in place for ease of implementation
	percept = "";
	encounter = "";
}

/*****************************************
 * Function: getPercept
 * Description: retrieves the percept string
 * from event
 * Parameters: none
 * Pre-Conditions: none
 * Post Conditions: returns data
*****************************************/

string Event::getPercept(){
	//returns the blank strring used for a percept
	return percept;
}

/*****************************************
 * Function: getEncounter
 * Description: retrieves the encounter string
 * from event
 * Parameters: none
 * Pre-Conditions: none
 * Post Conditions: returns data
*****************************************/


string Event::getEncounter(){
	return encounter;
}

/*****************************************
 * Function: ~Event
 * Description: destructs data held in the
 * class
 * Parameters: none
 * Pre-Conditions: data must be constructed
 * Post Conditions: destructs data
*****************************************/

Event::~Event(){

}
