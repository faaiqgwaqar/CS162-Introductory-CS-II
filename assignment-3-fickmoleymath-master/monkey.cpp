/*************************************
 * Filename: otter.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the logic and
 * class methodolgy derived from public
 * methods of the otter class
 * Input: header file declaration
 * Output: otter class logic
**************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

/**************************************
 * Function: otter : animal
 * Description: otter is a child class,
 * and this default constructor constructs
 * using defaults used in default animal
 * constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Consitions: data is constructed
**************************************/

Otter::Otter():Animal(){}

/**************************************
 * Function: otter : animal (parameterized)
 * Description: uses a parameterized constructor
 * to construct the information, and using the 
 * logic from the parent animal class parameter
 * constructor
 * Parameters: 2 ints and 3 doubles
 * Pre-Conditions: must pass in 5 numbers
 * Post-Consitions: object is constructed
**************************************/

Otter::Otter(int newAge,
	double newCost,
	int newNumberOfBabies,
	double newBaseFoodCost,
	double newPayoff):Animal(newAge,
		newCost,
		newNumberOfBabies,
		newBaseFoodCost,
		newPayoff){}

/**************************************
 * Function: ~otter
 * Description: destructs data held specific
 * to the otter class
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Consitions: object is destructed
**************************************/

Otter::~Otter(){

}

