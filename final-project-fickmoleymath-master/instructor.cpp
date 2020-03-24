/********************************************
 * Filename: instructor.cpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: conains the implementation of
 * the instructor class methods, some of which
 * are polymophically derived from the parent
 * person class
 * Input: header files for all headers in the 
 * program
 * Output: usable class methods that can be publically
 * accessed
********************************************/

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

/*******************************************
 * Function: instructor (constructor)
 * Description: constructor function that takes
 * the information in the instructor class and
 * instanciates it
 * Parameters: 2 integers used for the location
 * PreConditions: integers passed must be greater
 * than 0 and less than the max size of the maze
 * PostConditions: data of the instuctor class is 
 * constructed and usable
*******************************************/

Instructor::Instructor(int newValX,int newValY){
	satisfied = false;
	valX = newValX;
	valY = newValY;
}

/*******************************************
 * Function: getsatisfied
 * Description: accessor used to access the private
 * satisfied member in the instructor class
 * Parameters: none
 * PreConditions: none
 * PostConditions: the boolean value of the 
 * instructor class is accessed
*******************************************/


bool Instructor::getSatisfied(){
	return satisfied;
}

/*******************************************
 * Function: getmove
 * Description: polymorphed function that, for
 * the instructor, will pass a variable that
 * will cause it to do nothing, because the instructor
 * does not move
 * Parameters: none
 * PreConditions: none 
 * PostConditions: a character of n is returned to
 * the function call
*******************************************/


char Instructor::getMove(){
	return 'n';
}

/*******************************************
 * Function: getvalx
 * Description: accessor used to obtain the x
 * coordinate of the instructor
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns an integer that is 
 * stored in the valX variable
*******************************************/


int Instructor::getValX(){
	return valX;
}

/*******************************************
 * Function: getvaly
 * Description: accessor used to obtain the y
 * coordinate of the instructor
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns an integer that is
 * stored in the valY variable
*******************************************/


int Instructor::getValY(){
	return valY;
}

/*******************************************
 * Function: setsatisfied
 * Description: mutator used to modify existing
 * information in the satisfied boolean used for the
 * end of the game
 * Parameters: bool newsatisfied
 * PreConditions: bool can only be true or false val;
 * PostConditions: satisfied boolean is modified
*******************************************/


void Instructor::setSatisfied(bool newSatisfied){
	satisfied = newSatisfied;
}

/*******************************************
 * Function: setvalx
 * Description: mutator used to modify the
 * x coordinate of the instructor class
 * Parameters: integer newvalx
 * PreConditions: int cant be less than 0 or
 * greater that the bounds of the maze
 * PostConditions: the valx variable is mordified
*******************************************/


void Instructor::setValX(int newValX){
	valX = newValX;
}

/*******************************************
 * Function: setvaly
 * Description: mutator used to modify the
 * y coordinate of the instructor class
 * Parameters: integer newvaly
 * PreConditions: int cant be less than 0 or
 * greater than the bounds of the maze
 * PostConditions: the valy variable is modified
*******************************************/


void Instructor::setValY(int newValY){
	valY = newValY;
}

/*******************************************
 * Function: ~Instructor
 * Description: destructor used to remove the
 * data of the instructor class
 * Parameters: none
 * PreConditions: none
 * PostConditions: the memory is drallocated
 * for the instructor class
*******************************************/


Instructor::~Instructor(){

}
