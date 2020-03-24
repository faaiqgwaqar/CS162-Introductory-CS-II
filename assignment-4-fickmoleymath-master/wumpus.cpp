/**********************************
 * Filename: wumpus.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19 
 * Description: class implementation
 * of wumpus
 * Input: headers
 * Output: class implementation
**********************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

/****************************************
 * Function: wumpus
 * Description: constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
****************************************/

Wumpus::Wumpus(){
	//constructs information for string percept
	percept = "You smell a terrible stench.";
	encounter = "Encountered the Wumpus ... You are Consumed";
}

/****************************************
 * Function: getPercept
 * Description: accesor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data returned
****************************************/

string Wumpus::getPercept(){
	return percept;
}

/****************************************
 * Function: getEncounter
 * Description: accesor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data returned
****************************************/

string Wumpus::getEncounter(){
	return encounter;
}

/****************************************
 * Function: ~wumpus
 * Description: destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: destructed data
****************************************/

Wumpus::~Wumpus(){

}
