/**********************************************
 * Filename: ta.cpp 
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the implementation of
 * the ta child class
 * Inputs:header files from the intir program
 * Outputs: usable function implementation
**********************************************/

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

/**********************************************
 * Function: ta
 * Description: contains the constructor for
 * the ta class
 * Parameters: int newvalx and in newvaly
 * PreConditions: vals must be in bounds of
 * the map
 * PostConditions: contructs data for the ta class
**********************************************/

Ta::Ta(int newValX,int newValY){
	valX = newValX;
	valY = newValY;
	appeased = false;
	appeasedTime = 0;
}

/**********************************************
 * Function: getappeased
 * Description: acceasor for the appeased boolean
 * Parameters: none
 * PreConditions: none
 * PostConditions:retuns booleandata held in appeased
**********************************************/
bool Ta::getAppeased(){
	return appeased;
}

/**********************************************
 * Function: getmove
 * Description: decides the move for the ta class
 * Parameters: none
 * PreConditions: none
 * PostConditions: retuns 1 of 4 charectors
**********************************************/
char Ta::getMove(){
	srand(time(NULL));
	int direction = rand() % 4 + 1;
	switch (direction){
		case 1:
			return 'w';
			break;
		case 2:
			return 'a';
			break;
		case 3:
			return 's';
			break;
		case 4:
			return 'd';
			break;

	}	

	return 'n';
}

/**********************************************
 * Function: getvalx
 * Description: accessor for val x int
 * Parameters: none
 * PreConditions: none
 * PostConditions: retursn int in valx
**********************************************/
int Ta::getValX(){
	return valX;
}

/**********************************************
 * Function: getvaly
 * Description: accessor for the val y int
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns in in valy
**********************************************/
int Ta::getValY(){
	return valY;
}

/**********************************************
 * Function: getappeasedtime
 * Description: accessor for the appesed time int
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the int in appeasedtime
**********************************************/
int Ta::getAppeasedTime(){
	return appeasedTime;
}

/**********************************************
 * Function: setappeased
 * Description: mutator for the appeased boolean
 * Parameters: bool new appeased
 * PreConditions: must be 1 or 0
 * PostConditions: apeased mutated
**********************************************/
void Ta::setAppeased(bool newAppeased){
	appeased = newAppeased;
}

/**********************************************
 * Function: setvalx
 * Description: mutator for the val x integer
 * Parameters: int newvalx
 * PreConditions: must be in bounds of the maze
 * PostConditions: valx mutated
**********************************************/
void Ta::setValX(int newValX){
	valX = newValX;
}

/**********************************************
 * Function: setvaly
 * Description: mutator for the val y integer
 * Parameters: int newvaly
 * PreConditions: must be in bound of the maze
 * PostConditions: valy mutated
**********************************************/
void Ta::setValY(int newValY){
	valY = newValY;
}

/**********************************************
 * Function: setappeasedtime
 * Description: mutator for the appeased time
 * Parameters: int appeased time
 * PreConditions: must be pos or 0
 * PostConditions: mutates appeased tiem int
**********************************************/
void Ta::setAppeasedTime(int newAppeasedTime){
	appeasedTime = newAppeasedTime;
}

/**********************************************
 * Function: increment appeased time
 * Description: subtracts the appeased time by one
 * Parameters: none 
 * PreConditions: appeased time must be positive
 * PostConditions: subtracts one
**********************************************/
void Ta::incrementAppeased(){
	appeasedTime--;	
}
