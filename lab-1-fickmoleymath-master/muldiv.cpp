#include <iostream>
#include <cstdlib>
#include <cmath>
#include "muldiv.hpp"

using namespace std;
int main(int argc, char **argv){
	int rows = atoi(argv[1]);
	muldiv_entry **table;
	table = createTable(rows);
	mulEntry(table,rows);
	divEntry(table,rows);
	mulPrint(table,rows);
	divPrint(table,rows);
	cout << "\n";
	deleteTable(table,rows);
	return 0;
}

