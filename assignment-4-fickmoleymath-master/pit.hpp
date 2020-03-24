/********************************************
 * Filename: pit.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains declaration fo pit child
 * class
 * Input: libraries an event header
 * Output: declared class
********************************************/

#ifndef WAQARF_PIT_HPP
#define WAQARF_PIT_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "event.hpp"

class Pit : public Event{
	private:
		string percept;
		string encounter;
	public:
		Pit();
		string getEncounter();
		string getPercept();
		~Pit();
};

#endif
