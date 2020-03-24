/***************************************
 * Filename: main.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: 
 * Input: header files
 * Output: game output to screen
***************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

using namespace std;

int main(int argc, char** argv){
	int size = atoi(argv[1]);
	
	//uses throw statements to error handle the CMD LINE ARGS
	if(size < 5)
		throw 4;
	if(size > 12)
		throw 5;
	
	//initializes variables used for menu directionality
	int selection,direction,aiSelection;
	
	//initialize the map at runtime
	Map* map = new Map(size);
	//set the map
	map->setMap();
	//EXTRA CREDIT: initializing and checking menu for AI
	vector<string> menu3 = {"Play Yourself" , "AI Play"};
	aiSelection = valmenu(menu3);

	//User Implemented section of the program
	if(aiSelection == 1){
		//starts a do while loop to create initial set on selection 
		do{
			//checks if the player is alive and prints information
			if(map->encounter() == false)
				break;

			//prints important information to the screen
			map->printBoard();
			map->printEvent();
			
			//Initializes menu for user variability choice;
			vector<string> menu1 = {"Move Around","Shoot Arrow","End Game"};
			selection = valmenu(menu1);
			
			//Implementation of Move Functionality
			if(selection == 1){
				vector<string> menu2 = {"Upwards","Downwards","Leftwards","Rightwards"};
				direction = valmenu(menu2);
				map->moveAdventurer(direction);
			}

			//Implementation of Shoot Functionality
			else if(selection == 2){
				vector<string> menu2 = {"Upwards","Downwards","Leftwards","Rightwards"};
				direction = valmenu(menu2);
				map->shootArrow(direction);
			}
	
			cout << "__________________________________________________________________\n\n";
	
		}while(selection != 3);
	}

	//AI Implemented Section of the Program
	else if(aiSelection == 2){
		do{
			//Checks the status of the player in game and prints info
			if(map->encounter() == false)
				break;
			//Prints board and Event information
			map->printBoard();
			map->printEvent();

			//Initialized and validates menu for the AI, move and shoot
			vector<string> menu1 = {"Move Around","Shoot Arrow"};
			vector<string> menu4 = {"Move Around"};

			//will decide to shoot or not based on wumpus proximity and alive
			if(map->getAiWumpus() == false || map->getWumpus() == true)
				selection = aivalmenu(menu4);
			else if(map->getAiWumpus() == true && map->getWumpus() == false)
				selection = aivalmenu(menu1);

			//AI implementation of movement
			if(selection == 1){
				vector<string> menu2 = {"Upwards","Downwards","Leftwards","Rightwards"};
				direction = aivalmenu(menu2);
				map->moveAdventurer(direction);
			}
			//AI implementation of shooting
			else if(selection == 2){
				vector<string> menu2 = {"Upwards","Downwards","Leftwards","Rightwards"};
				direction = aivalmenu(menu2);
				map->shootArrow(direction);
			}
	
			cout << "__________________________________________________________________\n\n";
	
		}while(selection != 3);	
	}

	return 0;
}
