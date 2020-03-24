/******************************************
 * Filename: sloth.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contians functionality for
 * public functions in the sloth child class
 * Input: header files
 * Output: class construction and destruction
******************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

/*****************************************
 * Function: sloth : animal (defualt)
 * Description: default constuctor for sloth
 * child class using constructor method from
 * the animal class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is constructed
******************************************/

Sloth::Sloth():Animal(){}

/*****************************************
 * Function: sloth : animal (parameterized)
 * Description: parameterized constructor for
 * sloth child class using constructor method
 * from the animal class
 * Parameters: 2 ints and 3 doubles
 * Pre-Conditions: must pass 5 numbers
 * Post-Conditions: data is constructed
******************************************/

Sloth::Sloth(int newAge,
	double newCost,
	int newNumberOfBabies,
	double newBaseFoodCost,
	double newPayoff):Animal(newAge,
		newCost,
		newNumberOfBabies,
		newBaseFoodCost,
		newPayoff){}

/*****************************************
 * Function: ~sloth
 * Description: destruction of sloth class
 * data
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sloth class destructed
******************************************/

Sloth::~Sloth(){

}
