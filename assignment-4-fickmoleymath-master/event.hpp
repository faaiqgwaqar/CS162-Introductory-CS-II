/********************************************
 * Filename: bats.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: header file containing the 
 * parent class declaration of Event
 * Input: Libraries
 * Output: Class Declaration
********************************************/

#ifndef WAQARF_EVENT_HPP
#define WAQARF_EVENT_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Event {
	private:
		string percept;
		string encounter;
	public:
		Event();
		virtual string getEncounter();
		virtual string getPercept();
		~Event();
};

#endif
