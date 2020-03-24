/***************************************
 * Filename: bats.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: class initializing child
 * class Bats
 * Input: libraries and event header
 * Output: class initialization
***************************************/

#ifndef WAQARF_BATS_HPP
#define WAQARF_BATS_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "event.hpp"

using namespace std;

class Bats : public Event{
	private:
		string percept;
		string encounter;
	public:
		Bats();
		string getEncounter();
		string getPercept();
		~Bats();
};

#endif
