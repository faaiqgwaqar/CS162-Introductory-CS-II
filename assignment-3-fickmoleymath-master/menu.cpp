/*******************************************
 * Filename: menu.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains function resposible for
 * menu handling for all menus
 * Input: libraries, menu header
 * Output: validation format for error handling
*******************************************/

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "animal.hpp"
#include "menu.hpp"

using namespace std;

/*****************************************
 * Function: valmenu
 * Description: takes in a vector of stings
 * organizes them into a printable menu, takes 
 * input, and validates it
 * Parameters: vector of string
 * Pre-Conditions: string of option can not
 * contain 0 options
 * Post-Conditions: menu printed and validated
*****************************************/

int valmenu(vector <string> options){
	int selection, optionnum = 1;
	bool valid = false;
	
	cout << "Select One of The Following: \n";
	
	for (string option:options){
		cout << optionnum << "-" << option << "\n";
		optionnum += 1;
	}
	
	int choices = options.size();
	
	while (valid == false){
		cin >> selection;
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
