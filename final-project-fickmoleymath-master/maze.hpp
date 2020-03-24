/**************************************************
 * Filename: maze.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the declaration fo the maze
 * class
 * Inputs: header files and c librareis
 * Outputs: maze class declaration for use
**************************************************/

#ifndef WAQARF_MAZE_HPP
#define WAQARF_MAZE_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "instructor.hpp"
#include "level.hpp"
#include "location.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

class Maze {
	private:
		int numLevels;
		int levelX,levelY,levelZ;
		
		vector<Level*> levels;
		
	public:
		Maze(ifstream&);

		bool endgame();	
	
		int getNumLevels();
		int getLevelX();
		int getLevelY();
		int getLevelZ();

		void setNumLevels(int);
		void setLevelX(int);
		void setLevelY(int);
		void setLevelZ(int);
		void printLevel(int);
		void incrementLevel();
		void setProgSkills();
		void moveTaLev(int);
		void moveStudLev(int);
		void testEncounter(int); 
		void printStudentSkills();
		void printAppeasementStatus();
		void printRules();
		~Maze();

};

#endif
