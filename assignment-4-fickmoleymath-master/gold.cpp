/***********************************************
 * Filename: gold.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains implementation for
 * tho gold child class
 * Input: Header files
 * Output: Implementation of the Gold Class
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

/*******************************************
 * Function: Gold
 * Description: Constructor for the gold class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
******************************************/

Gold::Gold(){
	//initializing respective percept
	percept = "You see a glimmer nearby.";
	encounter = "Encountered the Gold ... Picked It Up";
}

/*******************************************
 * Function: getPercept
 * Description: accessor to get percept string
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is returned
******************************************/

string Gold::getPercept(){
	return percept;
}

/*******************************************
 * Function: getEncounter
 * Description: accessor to get encounter string
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is returned
******************************************/

string Gold::getEncounter(){
	return encounter;
}


/*******************************************
 * Function: ~Gold
 * Description: destructor for the gold class
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Conditions: data destructed
******************************************/

Gold::~Gold(){

}
