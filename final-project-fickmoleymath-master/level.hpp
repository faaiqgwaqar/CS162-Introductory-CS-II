/**********************************************
 * Filename: level.hpp
 * Date:3/20
 * Author: faaiq waqar
 * Description: contains the declaration of the
 * level class
 * Inputs: c libraries and headers from all the
 * fucntion headers
 * Outputs: usable calss of level
**********************************************/

#ifndef WAQARF_LEVEL_HPP
#define WAQARF_LEVEL_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "instructor.hpp"
#include "location.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

class Level{
	private:
		Ta* TA1;
		Ta* TA2;
		Instructor* INST;
		Student* STUD;
		bool climbTime,instReset;
		int dimentionX,dimentionY;
		vector<vector<Location*> > locations;
	public:
		Level(ifstream& infile,int,int);
		
		bool getClimbTime();
		bool getInstReset();
		bool getInstSatisfied();
		
		int getTaAppeasement();
		int getDimentionX();
		int getDimentionY();
		int getStudProgSkills();

		void setStudProgSkills(int);
		void setDimentionX(int);
		void setDimentionY(int);
		void printBoard();
		void setProgSkills();
		void setTas();
		void moveTas();
		void setInstructor();
		void setStudent();
		void studentMove();
		void studentEncounter();
		void setClimbTime(bool);
		void resetEncounter();
		void incrementTaAppeased();
		void setInstReset(bool);

		~Level();
};

#endif
