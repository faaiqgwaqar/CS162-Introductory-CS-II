/****************************************
 * Filename: open.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the implementation
 * of the open class
 * Inputs: header files from whole program
 * Outputs; usable impleemtnation fo open methods
*****************************************/

#include "instructor.hpp"
#include "level.hpp"
#include "location.hpp"
#include "maze.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

/*****************************************
 * Function: open
 * Description: contructor for the open calss
 * Parameters: cha newcontainer,
 * int newbeggining, int newfinish,int newLadder
 * PreConditions: ints passedmust be 1 or 0
 * PostConditions: open is allocated
******************************************/

Open::Open(char newContainer, int newBeggining, int newFinish, int newLadder){
	isBeggining = newBeggining;
	isInstructor = false;
	isFinish = newFinish;
	isLadder = newLadder;
	isProgSkill = false;
	isStudent = false;
	isTa = false;

	setContainer(newContainer);
	setOccupiable();

	if(container == '%'){
		setInstructor(true);
		isOccupiable = false;
	}
}

/*****************************************
 * Function: getbeggining
 * Description: accessor that gets the
 * boolean for the beggning
 * Parameters: none
 * PreConditions: noen
 * PostConditions: returns the boolean data 
 * in isbeggning
******************************************/


bool Open::getBeggining(){
	return isBeggining;
}

/*****************************************
 * Function: getfinish
 * Description: accessor that gets the boolean
 * for the finish
 * Parameters: none
 * PreConditions: none
 * PostConditions: return sthe bolean data
 * in isfinish
******************************************/


bool Open::getFinish(){
	return isFinish;
}

/*****************************************
 * Function: getinstructor
 * Description: accesor that gets the boolean
 * for hte instructor
 * Parameters: noen
 * PreConditions: none
 * PostConditions: returns the boolean data
 * in isinstructor
******************************************/


bool Open::getInstructor(){
	return isInstructor;
}

/*****************************************
 * Function: getladder
 * Description: accesor that gets the boolean
 * fir the ladder
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean data
 * in isladder
******************************************/


bool Open::getLadder(){
	return isLadder;
}

/*****************************************
 * Function:getoccupiable
 * Description: accessor that gets the boolean
 * for the occupiable
 * Parameters: none
 * PreConditions: returns the boolean data
 * in occupaube
 * PostConditions:na
******************************************/


bool Open::getOccupiable(){
	return isOccupiable;
}

/*****************************************
 * Function: getprogskil
 * Description: accessor that gets the boolean
 * for the programing skill
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean data in 
 * is prog skill
******************************************/


bool Open::getProgSkill(){
	return isProgSkill;
}

/*****************************************
 * Function: getstudent
 * Description: accessot tat gets student
 * boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean data
 * in the studrnt
******************************************/


bool Open::getStudent(){
	return isStudent;
}

/*****************************************
 * Function: getta
 * Description: accessor for ta boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns booelan data in ista
******************************************/


bool Open::getTa(){
	return isTa;
}

/*****************************************
 * Function: getcontainer
 * Description: accessor for container char
 * Parameters: none 
 * PreConditions: none
 * PostConditions: returns char data in container
******************************************/


char Open::getContainer(){
	return container;
}

/*****************************************
 * Function: setbegging
 * Description: mutator for begging
 * Parameters: bool
 * PreConditions: 1 or 0
 * PostConditions: mutates tdata to patameter
******************************************/


void Open::setBeggining(bool newBeggining){
	isBeggining = newBeggining;	
}

/*****************************************
 * Function: setcontainer
 * Description: mutator for container
 * Parameters: char
 * PreConditions: must be singe char
 * PostConditions: mutatesdata to parameter
******************************************/


void Open::setContainer(char newContainer){
	container = newContainer;
}

/*****************************************
 * Function: setfinish
 * Description: mutator for finish
 * Parameters: bool
 * PreConditions: 1 or 0 
 * PostConditions: mutates data for finish
******************************************/


void Open::setFinish(bool newFinish){
	isFinish = newFinish;
}

/*****************************************
 * Function: setinstructor
 * Description: mutator for instructor
 * Parameters: bool
 * PreConditions: 1 or 0
 * PostConditions: mutated tot he parameter set
******************************************/


void Open::setInstructor(bool newInstructor){
	isInstructor = newInstructor;
}

/*****************************************
 * Function: setladder
 * Description: mutator for ladder
 * Parameters: bool 
 * PreConditions: 1 or 0
 * PostConditions: mutated to the parameter set
******************************************/


void Open::setLadder(bool newLadder){
	isLadder = newLadder;
}

/*****************************************
 * Function:setoccupiable
 * Description: sets occupiale to true for 
 * open spaces
 * Parameters: none
 * PreConditions: none
 * PostConditions: occiaible bool set true
******************************************/


void Open::setOccupiable(){
	isOccupiable = true;
}

/*****************************************
 * Function:setprogskill
 * Description: mutator for the prog skill
 * boolean
 * Parameters: bool 
 * PreConditions: can only be 0 or 1
 * PostConditions: progskill mutated
******************************************/


void Open::setProgSkill(bool newProgSkill){
	isProgSkill = newProgSkill;
}

/*****************************************
 * Function:setstudent
 * Description: mtator for the student
 * boolean
 * Parameters: bool
 * PreConditions: can onyl be 0 or 1
 * PostConditions: student mutated to parameter
******************************************/


void Open::setStudent(bool newStudent){
	isStudent = newStudent;
}

/*****************************************
 * Function: setta
 * Description: mutator for the ta boolean
 * Parameters: bool 
 * PreConditions:can only be 0 or 1
 * PostConditions: student mutated to parameter
******************************************/


void Open::setTa(bool newTa){
	isTa = newTa;
}

/*****************************************
 * Function: ~open
 * Description: destructor
 * Parameters: noen
 * PreConditions:none
 * PostConditions: memory deallocated
******************************************/


Open::~Open(){

}

