/**************************************************
 * Filename: wall.cpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the class implementation
 * for the wall child class
 * Inputs:  header files from the entire program
 * Outputs: function implementation of the wall class
**************************************************/

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

/**************************************************
 * Function: wall
 * Description: constructor for the wall class
 * Parameters: none
 * PreConditions: none
 * PostConditions: all private memebrs of the wall
 * are set
**************************************************/

Wall::Wall(){
	setBeggining(false);
	setContainer('#');
	setInstructor(false);
	setFinish(false);
	setLadder(false);
	setOccupiable();
	setProgSkill(false);
	setStudent(false);
	setTa(false);
}

/**************************************************
 * Function: getbeggining
 * Description: accessor for the beggining of the 
 * begginging boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean value in
 * the isbeggning member
**************************************************/
bool Wall::getBeggining(){
	return isBeggining;
}

/**************************************************
 * Function: getinstructor
 * Description: accessor for the beggining of the
 * indtructor boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean value in the
 * isinstructor boolean
**************************************************/
bool Wall::getInstructor(){
	return isInstructor;
}

/**************************************************
 * Function: getfinish
 * Description: accessor for the finish of the
 * finish boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returnsthe boolean value in the
 * isfinish boolean
**************************************************/
bool Wall::getFinish(){
	return isFinish;
}

/**************************************************
 * Function: getladder
 * Description: accessor for the value of the ladder
 * boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean value in the
 * isladder boolean
**************************************************/
bool Wall::getLadder(){
	return isLadder;
}

/**************************************************
 * Function: getoccupiable
 * Description: accessor for the value of the occupiable
 * boolean
 * Parameters: none
 * PreConditions: returns the boolean value in the 
 * is occupiable boolean
 * PostConditions:
**************************************************/
bool Wall::getOccupiable(){
	return isOccupiable;
}

/**************************************************
 * Function: getprogskill
 * Description: accessor for thr value of the
 * prog skill boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean val in the 
 * is prog skill boolean
**************************************************/
bool Wall::getProgSkill(){
	return isProgSkill;
}

/**************************************************
 * Function: getstudent
 * Description: accesor for the value of the
 * get student boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean val in the
 * is student boolean
**************************************************/
bool Wall::getStudent(){
	return isStudent;
}

/**************************************************
 * Function: getta
 * Description: accessor for the value of the 
 * is student boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the boolean val in the
 * is student boolean
**************************************************/
bool Wall::getTa(){
	return isTa;
}

/**************************************************
 * Function: getcontainer
 * Description: accessor for the value of the char
 * in the container char
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the char val in the container
 * val
**************************************************/
char Wall::getContainer(){
	return container;
}

/**************************************************
 * Function: setbeggining
 * Description: sets the boolean value in the isbegging
 * Parameters: bool newbegging
 * PreConditions: must be 1 or 0
 * PostConditions: isbegging modified to parameter
**************************************************/
void Wall::setBeggining(bool newBeggining){
	isBeggining = newBeggining;
}

/**************************************************
 * Function: setcontaier
 * Description: sets the char value in the container
 * member
 * Parameters: bool newcontainer
 * PreConditions: must be a single char
 * PostConditions: container modified to a parameter
**************************************************/
void Wall::setContainer(char newContainer){
	container = newContainer;
}

/**************************************************
 * Function: setinstructor
 * Description: sets the boolean value in the 
 * isntructor member
 * Parameters: bool newinstructor
 * PreConditions: must be 1 or 0
 * PostConditions: instructor bool modified to parameter
**************************************************/
void Wall::setInstructor(bool newInstructor){
	isInstructor = newInstructor;
}

/**************************************************
 * Function: setfinish
 * Description: sets the boolean value in the finish
 * member
 * Parameters: bool newfinish
 * PreConditions: must be 1 or 0
 * PostConditions: finish bool modified to the parameter
**************************************************/
void Wall::setFinish(bool newFinish){
	isFinish = newFinish;
}

/**************************************************
 * Function: setladder 
 * Description: modifies the ladder boolean
 * Parameters: bool new ladder
 * PreConditions: must be 1 or 0
 * PostConditions: sets the ladder bool to paramter
**************************************************/
void Wall::setLadder(bool newLadder){
	isLadder = newLadder;
}

/**************************************************
 * Function: setoccupiable
 * Description: modifies the occupiable bool
 * Parameters: none
 * PreConditions: none
 * PostConditions: sets occupiable to false
**************************************************/
void Wall::setOccupiable(){
	isOccupiable = false;
}

/**************************************************
 * Function: setprogskill
 * Description: modifies the prog skill boolean
 * Parameters: bool new prog skill
 * PreConditions: must be 1 or 0
 * PostConditions: sets the progskill bool to parameter
**************************************************/
void Wall::setProgSkill(bool newProgSkill){
	isProgSkill = newProgSkill;
}

/**************************************************
 * Function: setstudent
 * Description: modifies the student boolean
 * Parameters: bool new student
 * PreConditions: must be a 1 or 0
 * PostConditions: sets the student bool to parameter
**************************************************/
void Wall::setStudent(bool newStudent){
	isStudent = newStudent;
}

/**************************************************
 * Function: setta
 * Description: modifes the ta boolean
 * Parameters: bool newta
 * PreConditions: must be 1 or 0
 * PostConditions: setsthe ta bool to parameter
**************************************************/
void Wall::setTa(bool newTa){
	isTa = newTa;
}

/**************************************************
 * Function: ~wall
 * Description: wall descrutor
 * Parameters: none
 * PreConditions: none
 * PostConditions: deallocates data in wall
**************************************************/
Wall::~Wall(){

}
