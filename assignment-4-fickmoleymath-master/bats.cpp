/*********************************************
 * Filename: bats.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: implements functionality of
 * the bats class
 * Input: Headers
 * Output: Class Implementation
**********************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

/**********************************************
 * Function: Bats
 * Description: Default Constructor for the bat
 * class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
***********************************************/

Bats::Bats(){
	//sets the respective percept
	percept = "You hear wings flapping.";
	encounter = "Encountered Bats, Taken to New Room";
}

/**********************************************
 * Function: getPercept
 * Description: accessor that retrieves the percept
 * string
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
***********************************************/

string Bats::getPercept(){
	//returns the percept
	return percept;
}

/**********************************************
 * Function: getEncounter
 * Description: accessor that retrieves the encounter
 * string
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
***********************************************/

string Bats::getEncounter(){
	return encounter;
}

/**********************************************
 * Function: ~Bats
 * Description: destructor deletes data
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data destructed
***********************************************/

Bats::~Bats(){

}
