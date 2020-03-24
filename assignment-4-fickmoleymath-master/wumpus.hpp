/**************************************
 * Filename: wumpus.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Descriptions: class declaration for
 * the wumpus class
 * Input: libraries and event header
 * Output: wumpus declaration
**************************************/

#ifndef WAQARF_WUMPUS_HPP
#define WAQARF_WUMPUS_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "event.hpp"

using namespace std;

class Wumpus : public Event {
	private:
		string percept;
		string encounter;
	public:
		Wumpus();
		string getEncounter();
		string getPercept();
		~Wumpus();
};

#endif
