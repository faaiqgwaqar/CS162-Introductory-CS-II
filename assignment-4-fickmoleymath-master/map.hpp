/************************************
 * Filename: map.hpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: initializes map class for use
 * Input: libraries and header files
 * Output: Map class initialization
************************************/

#ifndef WAQARF_MAP_HPP
#define WAQARF_MAP_HPP

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
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

class Map{
	private:
		int size;
		int adX,adY,wumX,wumY;
		int arrows;
		bool wumpus;
		bool aiWumpus;
		bool gold;
		string rope1,rope2,rope3,arrows1,arrows2;
		vector<vector<Room*> > game;
	public:
		Map(int);
		void printEvent();
		void printBoard();
		void setMap();
		void moveAdventurer(int);
		void shootArrow(int);
		void wumpusMove();
		void memberSet(int);
		void batMove();
		void removeItem(int,int);
		bool encounter();
		bool getWumpus();
		bool getAiWumpus();
		~Map();
		
};

#endif
