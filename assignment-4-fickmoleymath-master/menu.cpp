/****************************************
 * Filename:menu.cpp
 * Author: Faaiq Waqar
 * Date: 03.04.19
 * Description: contains implementation
 * of menu validation for ai and player
 * Input: headers and unistd.h library
 * Output: menu validation menus
****************************************/

#include "bats.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"

#include <unistd.h>

using namespace std;

/*****************************************
 * * Function: valmenu
 * * Description: takes in a vector of stings
 * * organizes them into a printable menu, takes 
 * * input, and validates it
 * * Parameters: vector of string
 * * Pre-Conditions: string of option can not
 * * contain 0 options
 * * Post-Conditions: menu printed and validated
******************************************/

int valmenu(vector <string> options){
	int selection, optionnum = 1;
	bool valid = false;
	
	//prints the options and numbers them for selection
	cout << "Select One of The Following: \n";
	
	for (string option:options){
		cout << optionnum << "-" << option << "\n";
		optionnum += 1;
	}
	//figure out how many ptions there are through measure of the vectio
	int choices = options.size();
	
	//validate
	while (valid == false){
		cin >> selection;
		//make sure progam doesnt crash
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout<< "Enter a valid Integer\n";
		}
		//make sure a valid choice is picked
		else if (selection <=0 or selection > choices)
			cout<< "Enter a valid Integer\n";
		else
			valid = true;
	}
		
	//return it after implementation
	return selection;
}

/*****************************************
 * * Function: valmenu
 * * Description: takes in a vector of stings
 * * organizes them into a printable menu, takes 
 * * input, and validates it
 * * Parameters: vector of string
 * * Pre-Conditions: string of option can not
 * * contain 0 options
 * * Post-Conditions: menu printed and validated
******************************************/

int aivalmenu(vector <string> options){
	int selection, optionnum = 1;
	bool valid = false;
	
	cout << "Select One of The Following: \n";
	
	for (string option:options){
		cout << optionnum << "-" << option << "\n";
		optionnum += 1;
	}
	
	int choices = options.size();

	//randomly pick as an AI
	srand(time(NULL));
	//delay timer for 3s to make it look like its thinking
	sleep(3);
	while (valid == false){
		selection = rand()% choices+1;
		cout << selection << "\n";
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout<< "Enter a valid Integer\n";
		}
		else if (selection <=0 or selection > choices)
			cout<< "Enter a valid Integer\n";
		else
			valid = true;
	}
		
	return selection;
}
