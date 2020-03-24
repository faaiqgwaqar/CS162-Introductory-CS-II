#ifndef WAQARF_MULDIV_HPP
#define WAQARF_MULDIV_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct muldiv_entry {
	int mul;
	float div;
};

muldiv_entry** createTable(int);
void mulEntry(muldiv_entry **,int);
void divEntry(muldiv_entry **,int);
void mulPrint(muldiv_entry **,int);
void divPrint(muldiv_entry **,int);
void deleteTable(muldiv_entry **,int);

#endif
