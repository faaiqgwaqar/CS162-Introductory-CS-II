/**********************************************
 * Filename: person.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the class declaration for
 * the abstract class person, which is parent to the
 * ta, student and instructor
 * Inputs: c libraries
 * Outputs: usable parent class defninituon
 **********************************************/

#ifndef WAQARF_PERSON_HPP
#define WAQARF_PERSON_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
	private:
		int valX,valY;
	public:
		virtual char getMove() = 0;
		
		virtual int getValX() = 0;
		virtual int getValY() = 0;
		
		virtual void setValX(int) = 0;
		virtual void setValY(int) = 0;

};

#endif
