/*****************************************
 * Filename: gold.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: Contains the initialization
 * of the gold class
 * Input: libraries and event header
 * Output: class implementation
****************************************/

#ifndef WAQARF_GOLD_HPP
#define WAQARF_GOLD_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "event.hpp"

using namespace std;

class Gold : public Event {
	private:
		string encounter;
		string percept;
	public:
		Gold();
		string getEncounter();
		string getPercept();
		~Gold();
};

#endif	
