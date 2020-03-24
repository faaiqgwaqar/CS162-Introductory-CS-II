/*******************************************
 * Filename: instructor.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the declaration of the
 * instructor class, which is a child class of the
 * person class
 * Inputs: c type libraries and the person class
 * header file
 * Outputs:  usableinstructor class
********************************************/

#ifndef WAQARF_INSTRUCTOR_HPP
#define WAQARF_INSTRUCTOR_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"

using namespace std;

class Instructor : public Person {
	private:
		bool satisfied;
		int valX,valY;
	public:
		Instructor(int,int);
		
		bool getSatisfied();
		
		char getMove();
		
		int getValX();
		int getValY();
	
		void setSatisfied(bool);
		void setValX(int);
		void setValY(int);

		~Instructor();
	
};

#endif
