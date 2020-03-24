/*****************************************
 * Filename: monkey.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the fucntion methods
 * for public portions of the monkey class
 * Input: header files
 * Output: monkey class construction and destruction
******************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

/****************************************
 * Function: monkey : animal (default)
 * Description: default contructor for the 
 * child monkey class with methods from parent
 * animal class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is constructed
****************************************/

Monkey::Monkey():Animal(){}

/****************************************
 * Function: monkey : animal (parameterized)
 * Description: parameterized constructor for
 * the child monkey class eith methods from
 * parent animal class
 * Parameters: 2 ints and 3 doubles
 * Pre-Conditions: ints must be integers,
 * doubles must be numbers
 * Post-Conditions: data is constucted
****************************************/

Monkey::Monkey(int newAge,double newCost,
	int newNumberOfBabies,
	double newBaseFoodCost,
	double newPayoff):Animal(newAge,
		newCost,
		newNumberOfBabies,
		newBaseFoodCost,
		newPayoff){}

/****************************************
 * Function: ~monkey
 * Description: destructor for the monkey
 * class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: monkey spacific data destructed
****************************************/

Monkey::~Monkey(){

}

