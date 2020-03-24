#include <iostream>
#include <cstdlib>
#include <cmath>
#include "muldiv.hpp"

using namespace std;

muldiv_entry** createTable(int m){ //Create the 2D array for use
        muldiv_entry **table = new muldiv_entry *[m];
        for (int i = 0; i < m; i++) {
                table[i] = new muldiv_entry[m];
        }
        return table;
}

void mulEntry (muldiv_entry **table, int m){
        for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                        table[i][j].mul=((i+1)*(j+1));
                }
        }

}

void divEntry (muldiv_entry **table, int m){
        for (int i = 1; i <= m; i++){
                for (int j = 1; j <= m; j++){
                        table[i-1][j-1].div=((float)i/ (float)j);
                }
        }
}

void mulPrint (muldiv_entry **table, int m){
        cout <<"**************MULTIPLICATION TABLE***********************\n";
        for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                        cout << table[i][j].mul << " ";
                }
        cout << "\n";
        }
}

void divPrint (muldiv_entry **table, int m){
        cout <<"**************DIVISION TABLE***********************\n";
        for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                        cout << table[i][j].div << " ";
                }
        cout << "\n";
        }
}

void deleteTable(muldiv_entry **table, int m){
	for (int i=0; i<m; i++){
		delete [] table [i];
	}
	
	delete [] table;
}
