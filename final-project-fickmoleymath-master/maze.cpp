/********************************************
 * Filename: maze.cpp
 * Date: 3/20
 * Author: faaiq waqar
 * Desctiption: contains the class implementation
 * of the maze class
 * Inputs: header files from whole program
 * Outputs: usable function methods from maze class
*********************************************/

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
 * Function: maze
 * Description: constructor that will allocate
 * the array of maze levels, and sets default
 * information
 * Parameters: infile path
 * PreConditions: file path must be valid contaning
 * integers first
 * PostConditions: data of the maze class will be 
 * constructed and ready for implementation
*******************************************/

Maze::Maze(ifstream& infile){
	infile>>numLevels;
	infile>>levelX;
	infile>>levelY;

	levelZ = 0;

	for(int i = 0; i < numLevels; i++){
		levels.push_back(new Level(infile,levelX,levelY));
	}

}

/*******************************************
 * Function: endgame
 * Description: checks if the instructor is satisfied
 * in order to determine if the game shoudl end
 * Parameters: none
 * PreConditions: instructor cant be on level one
 * PostConditions: returns boolean data to
 * the function call aboit inst satisfaction
*******************************************/


bool Maze::endgame(){
	return levels[numLevels-1]->getInstSatisfied();
}

/*******************************************
 * Function: getnumlevels
 * Description: accessor that returns the 
 * number of levels
 * Parameters: none
 * PreConditions: none
 * PostConditions: reutrns int data held in
 * the newLvels int
*******************************************/


int Maze::getNumLevels(){
	return numLevels;
}

/*******************************************
 * Function: getlevelx
 * Description: accessor for the level col
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns integer data for
 * the levelx variable
*******************************************/


int Maze::getLevelX(){
	return levelX;
}

/*******************************************
 * Function: getlevely
 * Description: accessor for the level row
 * Parameters: none
 * PreConditions: none
 * PostConditions:retuns the integer data for
 * the levely variable
*******************************************/


int Maze::getLevelY(){
	return levelY;
}

/*******************************************
 * Function: getlevelz
 * Description: accessor that returns the accessed
 * level for all print and movement functions
 * Parameters: none
 * PreConditions: none 
 * PostConditions: returns level data for the
 * levlz variable
*******************************************/


int Maze::getLevelZ(){
	return levelZ;
}

/*******************************************
 * Function: setnumlevels
 * Description: sets the number of levels to
 * the maze
 * Parameters: integer new num levels
 * PreConditions: num levels cant be less than 1
 * PostConditions: num levels will be mutated to
 * parameter data
*******************************************/


void Maze::setNumLevels(int newNumLevels){
	numLevels = newNumLevels;
}

/*******************************************
 * Function: setlevelx
 * Description: sets the l rows of the maze
 * Parameters: int newlevelx
 * PreConditions: level x cant be less than 1
 * PostConditions: levelx is mutated to parameter
 * data
*******************************************/


void Maze::setLevelX(int newLevelX){
	levelX = newLevelX;
}

/*******************************************
 * Function: setlevely
 * Description: sets the cols of the maze
 * Parameters: int newlevely
 * PreConditions: levely cant be less than 1
 * PostConditions: levely is mutated to parameter
 * data
*******************************************/


void Maze::setLevelY(int newLevelY){
	levelY = newLevelY;
}

/*******************************************
 * Function: setlevelz
 * Description: sets the level data for seeking
 * Parameters: int newlevelz
 * PreConditions: levelz cant be less than 0
 * or greater than the number of levels
 * PostConditions: levelz is mutated to the parameter
 * data
*******************************************/


void Maze::setLevelZ(int newLevelZ){
	levelZ = newLevelZ;
}

/*******************************************
 * Function: printlevel
 * Description: prints a level fo the maze
 * Parameters: int index
 * PreConditions: index cant be smaller than
 * 0 or greater than number of levels
 * PostConditions: prints board level to the system
*******************************************/


void Maze::printLevel(int index){
	levels[index]->printBoard();
}

/*******************************************
 * Function: incrementlevel
 * Description: takes in data about the maze 
 * and chooses what to do about the values within
 * the maze
 * Parameters: none
 * PreConditions: none
 * PostConditions: the maze might be maniupualted
 * either clearing it and reset or by climbing the
 * ladder
*******************************************/


void Maze::incrementLevel(){
	//what if the ladder is climbed
	if(levels[levelZ]->getClimbTime() == true){
		levelZ++;
		levels[levelZ]->setStudProgSkills(levels[levelZ-1]->getStudProgSkills());
		levels[levelZ-1]->setClimbTime(false);
	}

	//what if the instructor is not satisfiesd
	if(levels[levelZ]->getInstReset() == true){
		for(int i = 0; i < levelZ; i++){
			levels[i]->resetEncounter();
			levels[i]->setInstReset(false);
		}

		levelZ = 0;
	}
}

/*******************************************
 * Function: set Prog skills, this
 * never worked so ignore this
 * Description:
 * Parameters:
 * PreConditions:
 * PostConditions:
*******************************************/


void Maze::setProgSkills(){

}

/*******************************************
 * Function: movetalev
 * Description: moves the tas on a specific
 * level
 * Parameters: index integer
 * PreConditions: index cant be less than 0
 * or greater than number of lvels
 * PostConditions: the tas on the indexed level
 * will move around
*******************************************/


void Maze::moveTaLev(int index){
	levels[index]->moveTas();
}

/*******************************************
 * Function: movestudlevel
 * Description: moves the student on a specific
 * level
 * Parameters: index
 * PreConditions: index cant be less than 0 or
 * greater that the numer of levels
 * PostConditions: the student will move on the 
 * indexed level
*******************************************/


void Maze::moveStudLev(int index){
	levels[index]->studentMove();
}

/*******************************************
 * Function: test encoutner
 * Description: calls to the student encounter
 * Parameters: index
 * PreConditions: index cant be less than 0 or
 * greater than number of levels
 * PostConditions: will test encounters of the
 * student permieter
*******************************************/


void Maze::testEncounter(int index){
	levels[index]->studentEncounter();
}

/*******************************************
 * Function: printstudentskills
 * Description: prints how many skills the student
 * has picked up
 * Parameters: none
 * PreConditions: none 
 * PostConditions: system prints
*******************************************/


void Maze::printStudentSkills(){
	cout << "*****************************************************************************\n";
	cout << "Student Has: " << levels[levelZ]->getStudProgSkills() << " Programing Skills\n";
	cout << "*****************************************************************************\n";
}

/*******************************************
 * Function: printappeasementstatus
 * Description: prints what the appeasement
 * status of the tas are
 * Parameters: none
 * PreConditions: none
 * PostConditions: system prints appeasement
 * information
*******************************************/


void Maze::printAppeasementStatus(){
	cout << "*****************************************************************************\n";
	if(levels[levelZ]->getTaAppeasement() == 0)
		cout << "The TAs Are Not Currently Appeased\n";
	else
		cout << "The TAs Are Appeased For " << levels[levelZ]->getTaAppeasement() << " Rounds\n";
	cout << "*****************************************************************************\n";
}

/*******************************************
 * Function: printrules
 * Description: prints the ruules of the
 * game
 * Parameters: none
 * PreConditions: none
 * PostConditions: system prints couts
*******************************************/


void Maze::printRules(){
	cout << "*****************************************************************************\n";
	cout << "RULES OF THE ESCAPE FROM CS MAZE:\n";
	cout << "1.Moves: W (up), A (left), S (down), D (Right)\n";
	cout << "2.Toggles: U (climb up the ladder), P (demonstrate programing skill)\n";
	cout << "*****************************************************************************\n";

}

/*******************************************
 * Function: ~maze
 * Description: maze descructor
 * Parameters: none
 * PreConditions: none
 * PostConditions: deallocated data of the maze
*******************************************/


Maze::~Maze(){

} 
