/***********************************************
 * Filename: animal.cpp
 * Author: Faaiq Waqar
 * Date: 2.16.19
 * Description: Contains constructors, destructor,
 * accessors and mutators for the animal class
 * Input: Header file for animal cpp, private
 * and public class information, parent class
 * Output: Constructed and destructed class information
***********************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

/*********************************************
 * Function: Animal default Constructor
 * Description: creation of a default animal is 
 * passed through this constructor
 * Parameters: none
 * Pre-Conditions: must exist under a class named
 * animal with these declared variables
 * Post-Conditions: constructed animal to 0
*********************************************/

Animal::Animal(){
	age = 0;
	numberOfBabies = 0;
	cost = 0.0;
	baseFoodCost = 0.0;
	payoff = 0.0;
}

/*********************************************
 * Function: Animal Parameterized Constructor
 * Description: creation of an animal using passed
 * in parameters for mutators
 * Parameters: 2 integers and 3 doubles
 * Pre-Conditions: must exist in a class with
 * varaibles parrallel to the parameters
 * Post-Conditions: constructed animal to parameters
*********************************************/

Animal::Animal(int newAge,double newCost,int newNumberOfBabies,double newBaseFoodCost,double newPayoff){
	age = newAge;
	cost = newCost;
	numberOfBabies = newNumberOfBabies;
	baseFoodCost = newBaseFoodCost;
	payoff = newPayoff;
}

/*********************************************
 * Function: getAge
 * Description: accessor function for age member
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns information to respective
 * call
*********************************************/

int Animal::getAge(){
	return age;
}

/*********************************************
 * Function: getNumberofBabies
 * Description: accessor function for number of
 * babies 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns information to respective
 * call
*********************************************/

int Animal::getNumberOfBabies(){
	return numberOfBabies;
}

/*********************************************
 * Function: getCost
 * Description: accessor function for the animal
 * cost
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns information to respective
 * call
*********************************************/

double Animal::getCost(){
	return cost;
}

/*********************************************
 * Function: getBaseFoodCost
 * Description: accessor function for the animal
 * base food cost
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns inforamtion to respective
 * call
*********************************************/

double Animal::getBaseFoodCost(){
	return baseFoodCost;
}

/*********************************************
 * Function: getPayoff
 * Description: gets the revenue collected
 * for the animal
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns information to respective
 * call
*********************************************/

double Animal::getPayoff(){
	return payoff;
}

/*********************************************
 * Function: setAge
 * Description: mutator that sets member to parameter
 * for age
 * Parameters: integer
 * Pre-Conditions: must pass in an int
 * Post-Conditions: age has been mutated
*********************************************/

void Animal::setAge(int newAge){
	age = newAge;
}

/*********************************************
 * Function: setnumberofbabies
 * Description: mutator that sets member to parameter
 * for number of babies
 * Parameters: integer
 * Pre-Conditions: must pass in an int
 * Post-Conditions: babies has been mutated
*********************************************/

void Animal::setNumberOfBabies(int newNumberOfBabies){
	numberOfBabies = newNumberOfBabies;
}

/*********************************************
 * Function:  setcost
 * Description: mutator that sets parameter to
 * the cost of an animal
 * Parameters: double
 * Pre-Conditions: must pass in a number
 * Post-Conditions: cost has been mutated
*********************************************/

void Animal::setCost(double newCost){
	cost = newCost;
}

/*********************************************
 * Function: setbasefoodcost
 * Description: sets the base food cost for
 * the specific animal
 * Parameters: double
 * Pre-Conditions: must pass in a number
 * Post-Conditions: basefoodcost has been mutated
*********************************************/

void Animal::setBaseFoodCost(double newBaseFoodCost){
	baseFoodCost = newBaseFoodCost;
}

/*********************************************
 * Function: setpayoff
 * Description: sets the payoff for a respective
 * animal
 * Parameters: double
 * Pre-Conditions: must pass in a number
 * Post-Conditions: payoff has been mutated
*********************************************/

void Animal::setPayoff(double newPayoff){
	payoff = newPayoff;
}

/*********************************************
 * Function: ~animal
 * Description: destrutor element for animal
 * class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is destructed
*********************************************/

Animal::~Animal(){

}
