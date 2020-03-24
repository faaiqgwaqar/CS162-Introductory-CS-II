/*********************************************
 * Filename:
 * Author:
 * Date:
 * Description:
 * Input:
 * Output:
*********************************************/

#ifndef WAQARF_ROOM_HPP
#define WAQARF_ROOM_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "wumpus.hpp"

using namespace std;

class Room {
	private:
		Event* events;
		int whichEvent;
		bool adventurer;	
	public:
		Room();
		int getWhichEvent();
		void setWhichEvent(int);
		bool getAdventurer();
		void setAdventurer(bool);
		void setEvent(int);
		string getEntrance();
		string getEvent();
		~Room();
};

#endif
