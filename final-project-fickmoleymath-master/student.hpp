/*******************************************
 * Filename: student.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the class declaration
 * for the student class
 * Inputs: c libraries
 * Outputs: usable class decalration of
 * the student class
*******************************************/

#ifndef WAQARF_STUDENT_HPP
#define WAQARF_STUDENT_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student : public Person {
	private:
		int valX,valY;
		int skillsObtained;
		bool canClimb;
	public:
		Student(int,int);
		
		bool getCanClimb();
	
		char getMove();
		
		int getValX();
		int getValY();
		int getSkillsObtained();
		
		void setValX(int);
		void setValY(int);
		void setSkillsObtained(int);
		void setCanClimb(bool);

		~Student();

};

#endif
