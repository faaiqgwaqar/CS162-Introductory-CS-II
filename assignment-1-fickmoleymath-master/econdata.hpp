/***********************************************
 * Program Filename: ECONDATA.HPP
 * Author: FAAIQ G WAQAR
 * Date: 01.21.19
 * Description: INTRODUCES LIBRARIES, FUNCTION
 * HEADERS, AND STRUCT DECLARATIONS TO BE USED
 * IN THE REST OF THE PROGRAM.
 * Input: N/A
 * Output: USABLE HEADER LIBRARY
***********************************************/

#ifndef WAQARF_ECONDATA_HPP //HEADER GUARDS TO ELMINATE REPEAT INFO
#define WAQARF_ECONDATA_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct state{
	string name;
	float unemployed2007;
	float unemployed2015;
	int medianIncome;
	struct county* counties;
	int numCounties;
};

struct county{
	string name;
	float unemployed2007;
	float unemployed2015;
	int medianIncome;
};

struct state* createStates(int);
struct county* createCounties(int);
void readStates(struct state*,int,ifstream&);
void readCounties(struct county*,int,ifstream&);
void highIncome (struct state*,int);
void lowIncome (struct state*,int);
void highUnemployed (struct state*,int);
void lowUnemployed (struct state*,int);
void empSort (struct state*,int);
void incSort (struct state*,int);
void countyFunc (struct state*,int);
void memClear(struct state*,int);

#endif
