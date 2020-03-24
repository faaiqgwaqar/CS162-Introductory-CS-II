/****************************************************
 * Filename: main.cpp 
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the main implementation of
 * the game
 * Inputs: header files from whole program
 * Outputs: program implementation through main
****************************************************/

#include "instructor.hpp"
#include "location.hpp"
#include "level.hpp"
#include "maze.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

#include <termios.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv){
	bool endgame = false;
	ifstream infile;
	infile.open(argv[1]);
	
	if(infile.fail()){
		throw 404;	
	}
	
	Maze m(infile);
	infile.close();

	m.printRules();	
	m.printStudentSkills();
	m.printLevel(m.getLevelZ());
	cout << "\n\n";

	while(endgame == false){
		m.moveTaLev(m.getLevelZ());
		m.moveStudLev(m.getLevelZ());
		system("clear");
		cout << "*****************************************************************************\n";
		cout << "MESSAGES:\n";
		m.incrementLevel();	
		m.testEncounter(m.getLevelZ());
		cout << "*****************************************************************************\n";		
		m.printRules();
		m.printStudentSkills();
		m.printAppeasementStatus();
		m.printLevel(m.getLevelZ());
		endgame = m.endgame();
		cout << "\n\n";

	}

	return 0;
}
