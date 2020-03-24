/**********************************************
 * Filename: ta.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains class declaration for
 * child class ta 
 * PreConditions: c livraries
 * PostConditions: usable class declaration
***********************************************/

#ifndef WAQARF_TA_HPP
#define WAQARF_TA_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ta : public Person {
	private:
		int valX,valY,appeasedTime;
		bool appeased;
	public:
		Ta(int,int);
		
		bool getAppeased();
		
		char getMove();
		
		int getValX();
		int getValY();
		int getAppeasedTime();

		void setAppeased(bool);
		void setValX(int);
		void setValY(int);
		void setAppeasedTime(int);
		void incrementAppeased();
		
};

#endif
