/********************************************
 * Filename: map.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains the functionality for
 * the map as a whole, which encompases the other
 * objects
 * Input: Headers
 * Output: Map class implementation
********************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

/******************************************
 * Function: Map
 * Description: Parameterized constructor
 * that creates the  Map 2d array
 * Parameters: integer
 * Pre-Conditions: size must be greater than 0
 * (although it uses throw in the main)
 * Post-Conditions: Data Constructed
 *****************************************/

Map::Map(int newSize){
	//constructs important information to basic
	//size is parameterized via CMD LINE ARG
	size = newSize;
	arrows = 3;
	wumpus = false;
	gold = false;
	rope1 = "GOLD: Y WUMPUS: Y ... WINNER";
	rope2 = "GOLD: Y WUMPUS: N ... Kill The Wumpus";
	rope3 = "GOLD: N WUMPUS: Y ... Grab The Gold";
	arrows1 = "ARROWS: 0 WUMPUS: Y ... LOSER";
	arrows2 = "ARROWS: 0 WUMPUS: N ... CONTINUE";

	//Implementation of a 2D Vectior, each containing a room class
	for(int i = 0; i < size; i++){
		vector<Room*> in;
		for (int j = 0; j < size; j++){
			in.push_back(new Room);
		}
		game.push_back(in);
	}
}

/******************************************
 * Function: printEvent
 * Description: prints the events in proximity
 * to the adventurer and collects data for the AI
 * to use
 * Parameters: none
 * Pre-Conditions: 2d vector must be constructed
 * and size has to be greater than 0
 * Post-Conditions: aiWumpus manipulated
 *****************************************/

void Map::printEvent(){
	aiWumpus = false;
	cout << "Events Near You:\n";
	//Checks to the Right of the Player
	if((adX + 1) < size && game[adX+1][adY]->getWhichEvent() != 1){
		cout << game[adX+1][adY]->getEvent() << "\n";
			//check for wumpus for ai
			if(game[adX+1][adY]->getWhichEvent() == 2)
				aiWumpus = true;
	}
	//Checks to the Left of the Player
	if((adX - 1) >= 0 && game[adX-1][adY]->getWhichEvent() != 1){
		cout << game[adX-1][adY]->getEvent() << "\n";
			//check for wumpus for ai
			if(game[adX-1][adY]->getWhichEvent() == 2)
				aiWumpus = true;
	}
	//Checks below the Player
	if((adY + 1) < size && game[adX][adY+1]->getWhichEvent() != 1){
		cout << game[adX][adY+1]->getEvent() << "\n";
			//check for wumpus for ai
			if(game[adX][adY+1]->getWhichEvent() == 2)
				aiWumpus = true;
	}
	//Checks above the player
	if((adY - 1) >= 0 && game[adX][adY-1]->getWhichEvent() != 1){
		cout << game[adX][adY-1]->getEvent() << "\n";
			//check for wumpus for ai
			if(game[adX][adY-1]->getWhichEvent() == 2)
				aiWumpus = true;
	}

}

/******************************************
 * Function: printBoard
 * Description: prints the board to the screen
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: prints to system out
 *****************************************/

void Map::printBoard(){
	//Initial for loop for Top Bar Barier
	for(int i = 0; i < size; i++)
		cout << "__ _";
	cout << "\n";
	
	//Middle for loop for player printing on screen
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			switch(game[i][j]->getAdventurer()){
				case 0:
					cout << " ";
					break;
				case 1:
					cout <<  "*";
					break;
			}
			cout << " | ";
		}
	cout << "\n";

	//Final for loop for Bottom Bar Barier
	for(int i = 0; i < size; i++)
        	cout << "__ _";
	cout << "\n";
	}
}

/******************************************
 * Function: memberSet
 * Description: sets the members into the 
 * array during initialization
 * Parameters: integer for the initializer
 * Pre-Conditions: type has to be greater than
 * 0 and less than 6
 * Post-Conditions: sets data
 *****************************************/

void Map::memberSet(int type){
	//uses variables to set to new location
	int setX,setY;
	//checks if ha got a valid location to cut loop
	bool set = false;
	//loop that will find a valid location and set
	while (set == false){
		//rand starting at zero to the size
		setX = rand()%size;
		setY = rand()%size;
		//checks if it is a valid location, and sets the type
		if(game[setX][setY]->getWhichEvent() == 0){
			game[setX][setY]->setWhichEvent(type);
			set = true;
			}
		//Initialize coordinate systems
		//wumpus
		if(type == 2){
			wumX = setX;
			wumY = setY;
		}
		//adventurer;
		if(type == 1){
			adX = setX;
			adY = setY;
			game[adX][adY]->setAdventurer(true);
		}
	}

}

/******************************************
 * Function: setMap
 * Description: set map for initialization and
 * usage
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data set dynammically
 *****************************************/

void Map::setMap(){
	//sets the members of the game
	//Rope set first
	memberSet(1);
	//Wumpus set Second
	memberSet(2);
	//Gold set Third
	memberSet(3);
	//Pits set Forth
	memberSet(4);
	memberSet(4);
	//SuperBats set Fifth
	memberSet(5);
	memberSet(5);

	//Correlates the event settings to the percepts
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//the value at one is the rope, which doesnt have its own percept
			//Fix by maybe making a rope class?
			if(game[i][j]->getWhichEvent() != 1)
				game[i][j]->setEvent(game[i][j]->getWhichEvent());
			}

		}
}

/******************************************
 * Function: moveAdventure
 * Description: contains logic to move the 
 * adventurer around the map
 * Parameters: integer from valmenu
 * Pre-Conditions: dir cant be greater that
 * 4 or less than 1
 * Post-Conditions: adventurer coordinates
 * are manipulated
 *****************************************/

void Map::moveAdventurer(int dir){
	//movement system of the player, dir takin in from menu
	//move up
	if(dir==1 && (adX-1)>=0){
		game[adX][adY]->setAdventurer(false);
		adX--;
		game[adX][adY]->setAdventurer(true);
	}
	//move down
	else if(dir==2 && (adX+1) < size){
		game[adX][adY]->setAdventurer(false);
		adX++;
		game[adX][adY]->setAdventurer(true);

	}
	//move left
	else if(dir==3 && (adY-1) >= 0){
		game[adX][adY]->setAdventurer(false);
		adY--;
		game[adX][adY]->setAdventurer(true);
	}
	//move right
	else if(dir==4 && (adY+1) < size){
		game[adX][adY]->setAdventurer(false);
		adY++;
		game[adX][adY]->setAdventurer(true);	
	}
	//invalid move
	else{
		cout << "Move is Out of Map\n";
	}
}

/******************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *****************************************/

void Map::shootArrow(int dir){
	//set the initial arrow locations at the player
	int arrX = adX;
	int arrY = adY;
	
	//first check if the wumpus is even alive, why shoot otherwise
	if(wumpus == true){
		cout << "Wumpus Has Already Been Killed ... \n";
		return;
	}

	//loop for three rooms,increment as necessary
	for(int i = 0; i < 3; i++){
		//up
		if(dir==1 && (arrX-1)>=0)
			arrX--;
		//down
		else if(dir == 2 && (arrX+1) < size)
			arrX++;
		//left
		else if(dir==3 && (arrY-1) >= 0)
			arrY--;
		//right
		else if(dir==4 && (arrY+1) < size){
			arrY++;
		}
		
		//does it kill the wumpus
		if(arrX == wumX && arrY == wumY){
			cout << "The Arrow Pierced the Wumpuses Heart\n";
			//clear the implemented wumpus on the map
			removeItem(wumX,wumY);
			//change the bool because the wumpus is dead
			wumpus = true;
			//break the loop
			break;
		}
		
	}
	//if the wumpus is not killed by the end of the loop, move it
	if(wumpus == false){
		wumpusMove();
	}
}

/******************************************
 * Function: wumpusMove
 * Description: moves the wumpus (maybe) if
 * the wumpus is missed by an arrow
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: wumpus coordinates are 
 * manipulated
 *****************************************/

void Map::wumpusMove(){
		//used for rand
		srand(time(NULL));
			
		//notify how many arrows remain after shooting
		cout << "Arrow missed ... \n";
		arrows--;
		cout << arrows << " Arrows Remain ... \n";
	
		//bool set = false;
		//give a 75% chance of movement
		int chance = rand()%4;

		if(chance != 4){
			cout << "Wumpus has Awoken and Is Moving ... \n";
			game[wumX][wumY]->setWhichEvent(0);
			game[wumX][wumY]->setEvent(0);
			
			memberSet(2);
			game[wumX][wumY]->setEvent(2);
	}
}

/******************************************
 * Function: batMove
 * Description: moves the adventurer is they
 * step into a room with the bats
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: adventurer coordinates
 * manipulated
 *****************************************/

void Map::batMove(){
	//randomly moves the player around
	srand(time(NULL));
	int setX,setY;
	game[adX][adY]->setAdventurer(false);
	bool set = false;
	while (set == false){
		setX = rand()%size;
		setY = rand()%size;
		if(game[setX][setY]->getWhichEvent() == 0){
			adX = setX;
			adY = setY;
			game[adX][adY]->setAdventurer(true);
			set = true;
		}
	}
}

/******************************************
 * Function: encounter
 * Description: retrieves encounter data
 * based on the 
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Conditions: data maniupulated
 *****************************************/

bool Map::encounter(){
	//check if out of arrows, terminate if the wumpus hasnt been killed
	if(arrows == 0 && wumpus == false){
		cout << arrows1 << "\n\n";
		return false;
	}
	//check if out of arrows, do not terminate if the wumpus has been killed
	else if(arrows == 0 && wumpus == true){
		cout << arrows2 << "\n\n";
	}
	
	//switch for event that the adventurer is in
	switch(game[adX][adY]->getWhichEvent()){
		//if in the room with the rope
		case 1:
			//Win game
			if(gold == true && wumpus == true){
				cout << rope1 << "\n\n";
				return false;
			}
			//Need to Kill the wumpus
			else if(gold == false && wumpus == true){
				cout << rope2 << "\n\n";
				return true;
			}
			//need to grab the gold
			else if(gold == true && wumpus == false){
				cout << rope3 << "\n\n";
				return true;
			}
			break;
		//if in the room with the wumpus
		case 2:
			cout << game[adX][adY]->getEntrance() << "\n\n";;
			return false;
			break;
		//if in the room with the gold
		case 3:
			cout << game[adX][adY]->getEntrance() << "\n\n";
			gold = true;
			//make sure the percepts dont show up on the map and cant pick
			//it up twice
			removeItem(adX,adY);
			return true;
			break;
		//if in the room with the pit
		case 4:
			cout << game[adX][adY]->getEntrance() << "\n\n";
			return false;
			break;
		//if in the room with the bats
		case 5:
			cout << game[adX][adY]->getEntrance() << "\n\n";
			//randomly sets a new location for the player
			batMove();
			return true;
			break;
	}

	return true;
}

/******************************************
 * Function: getWumpus 
 * Description: returns the wumpul bool
 * to the AI
 * Parameters:none
 * Pre-Conditions: none
 * Post-Conditions: returns data
 *****************************************/

bool Map::getWumpus(){
	return wumpus;
}

/******************************************
 * Function: getAiWumpus
 * Description: returns the wumpus proximity
 * to the AI
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data
 *****************************************/

bool Map::getAiWumpus(){
	return aiWumpus;
}

/******************************************
 * Function: removeItem
 * Description: removes an object on the
 * map for a secific event
 * Parameters: x,y (integers)
 * Pre-Conditions:  x and y cant be less than
 * 0 or greater than the map size
 * Post-Conditions: data manipulated
 *****************************************/

void Map::removeItem(int x,int y){
	//change what the player can see on the map
	game[x][y]->setWhichEvent(0);
	//change the percept at that location
	game[x][y]->setEvent(0);
}

/******************************************
 * Function: ~Map
 * Description: map destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: destructs data
 *****************************************/

Map::~Map(){

}
