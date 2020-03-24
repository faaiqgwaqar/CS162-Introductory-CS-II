#ifndef WAQARF_STUDENT_HPP
#define WAQARF_STUDENT_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
	private:
		int studentX,studentY;
		char move;
	public:
		Student();
		
		int getStudentX();
		int getStudentY();
		void setStudentX(int);
		void setStudentY(int);
		char getMove();
		void setMove(char);
				

};

#endif
