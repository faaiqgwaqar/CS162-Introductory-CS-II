/**************************************************
 * Filename: student.cpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contians function implementation of
 * the student class
 * Inputs: head files for the entire program
 * Outputs: function implementaion of the student 
 * class
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

/************************************************
 * Function: student
 * Description: constructs data for the student 
 * class
 * Parameters: int valx and int valy
 * PreConditions: valx and valy must be within
 * bounds of the maze
 * PostConditions: data in student is constructed
************************************************/

Student::Student(int newValX,int newValY){
	skillsObtained = 0;
	canClimb = false;
	valX = newValX;
	valY = newValY;	
}

/************************************************
 * Function: getcanclimb
 * Description: returns the boolean held in can
 * climb, indicating if the student can climb at
 * that position
 * Parameters: none
 * PreConditions: none
 * PostConditions: data in the can climb boolean is
 * returned
************************************************/
bool Student::getCanClimb(){
	return canClimb;
}

/************************************************
 * Function: getmove
 * Description: calls to the menu in order
 * to get the user input for the users move
 * Parameters: none
 * PreConditions: none
 * PostConditions: a status charector determined
 * by the menu is returned to the function call
************************************************/
char Student::getMove(){
	vector<string> menu = {"w","a","s","d","p","u"};
	char status = valmenu(menu);
	return status;
}

/************************************************
 * Function: getvalx
 * Description: returns the integer giving to x pos
 * of the student
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns integer data stored in
 * valx
************************************************/
int Student::getValX(){
	return valX;
}

/************************************************
 * Function: getvaly
 * Description: returns the integer giving ttoy pos
 * of the student
 * Parameters: none 
 * PreConditions: none
 * PostConditions: returs integer data stored in 
 * valy
************************************************/
int Student::getValY(){
	return valY;
}

/************************************************
 * Function: getskillsobtained
 * Description: returns the integer value related to
 * the number of programming skills the student has
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns ingete data stored in skills
 * obtained 
************************************************/
int Student::getSkillsObtained(){
	return skillsObtained;
}

/************************************************
 * Function: setvalx
 * Description: mutator that modifies the valx
 * member of student
 * Parameters: int newvalx
 * PreConditions: parameter must be in bounds of the
 * map rows
 * PostConditions: valx modified to parameter
************************************************/
void Student::setValX(int newValX){
	valX = newValX;
}

/************************************************
 * Function: setvaly
 * Description: mutator that modifies the valy
 * member of the student
 * Parameters: int newvaly
 * PreConditions: parameter must be in bounds of
 * the map columns
 * PostConditions: valy modieifes to parameter
************************************************/
void Student::setValY(int newValY){
	valY = newValY;
}

/************************************************
 * Function: setskillsobtained
 * Description: mutator that modifes the skills
 * obtained memeber of the student
 * Parameters: int newskillsobtained 
 * PreConditions: parameters cant be less than 0
 * PostConditions: skills obtained bodified to
 * the patameter
************************************************/
void Student::setSkillsObtained(int newSkillsObtained){
	skillsObtained = newSkillsObtained;
}

/************************************************
 * Function: setcanclimb
 * Description: mutator that modifies the can
 * climb member of the student
 * Parameters: bool newcanclimb
 * PreConditions: paramter can only be 1 or 0
 * PostConditions: can climb modifies to
 * the parameter
************************************************/
void Student::setCanClimb(bool newCanClimb){
	canClimb = newCanClimb;
}

/************************************************
 * Function: ~student
 * Description: destructor for the student class
 * Parameters: none
 * PreConditions: none
 * PostConditions: memory deallocated
************************************************/
Student::~Student(){

}
