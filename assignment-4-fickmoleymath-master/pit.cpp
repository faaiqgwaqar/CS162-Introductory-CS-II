/******************************************
 * Filename: pit.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains the implementation
 * of the pit child class
 * Input: Headers
 * Output: class implementation for pit
******************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

/*****************************************
 * Function: pit constructor
 * Description: constructs pit data
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
*****************************************/

Pit::Pit(){
	//constructs the string
	percept = "You feel a breeze.";
	encounter = "Encountered a Pit ... Fell in and Died";
}

/*****************************************
 * Function: getPercept
 * Description: percept accessor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
*****************************************/

string Pit::getPercept(){
	return percept;
}

/*****************************************
 * Function: getEncounter
 * Description: encounter accessor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
*****************************************/

string Pit::getEncounter(){
	return encounter;
}

/*****************************************
 * Function: ~pit
 * Description:pit destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data destructed
*****************************************/

Pit::~Pit(){

}
