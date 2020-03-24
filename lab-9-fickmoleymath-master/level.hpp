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
	//	bool isInstructor;	
	
		int dimentionX,dimentionY;
		int startX,startY;
		int endX,endY;
		bool isStudent;
		Student s1;
	
		vector<vector<Location*> > locations;
	public:
		Level();
		
		int getDimentionX();
		int getDimentionY();

		void setDimentionX(int);
		void setDimentionY(int);
		void printBoard();
		void movePlayer();

		bool checkEnd();

//		bool getisStudent();
//		void setisStudent();

		~Level();
};

#endif
