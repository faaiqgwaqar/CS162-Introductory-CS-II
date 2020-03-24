/**************************************************
 * Program Filename: EXPLORE_ECONDATA.CPP
 * Author: FAAIQ G WAQAR
 * Date: 01.21.19
 * Description: EXPLORE_ECONDATA HOUSES THE MAIN 
 * FUNCTION, WHICH ALLOWS FOR COMMAND LINE ARGS
 * USER INPUT AND CALLS TO FUNCTIONS IN THE PROGRAM
 * Input: COMMAND LINE ARGS
 * Output: RETURN 0
************************************************/

#include "econdata.hpp" 
using namespace std;

int main(int argc, char** argv){
	int numStates,selection;
	ifstream infile;

	infile.open(argv[1]); //uses the second arg in argv
	if (infile.fail()) { 
		cout << "File Failed to Open ... Try Checking Your Entry\n"; //
		return 1;
	}

	infile >> numStates;
//	cout << numStates << "\n";
	struct state *states = createStates(numStates);
	
	for (int i = 0;i < numStates; i++) {
		readStates(states,i,infile);
		states[i].counties = createCounties(states[i].numCounties);
		readCounties(states[i].counties,states[i].numCounties,infile);
	}
	
	do {
	
		cout << "File Loaded ... \n\n";
		cout << "Menu ... \n";
		cout << "1. Print State High Med Income ... \n";
		cout << "2. Print State Low Med Income ... \n";
		cout << "3. Print State High Unemployment 2015 ... \n";
		cout << "4. Print State Low Unemployment 2015 ... \n";
		cout << "5. Print States Sorted by Change in Unemployment 2007 to 2015 ... \n";
		cout << "6. Print States Sorted by Change in Med Income ... \n";
		cout << "7. Select a State and Then ... \n";
		cout << "8. EXIT PROGRAM ... \n";

		cin >> selection;

		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid\n";
		}
			
	
		if (selection > 0 && selection <= 8){
			string stateName;
			switch (selection){
			case 1:
				highIncome(states,numStates);
				break;
			case 2:
				lowIncome(states,numStates);
				break;
			case 3:
				highUnemployed(states,numStates);
				break;
			case 4:
				lowUnemployed(states,numStates);
				break;	
			case 5:
				empSort(states,numStates);
				break;
			case 6:
				incSort(states,numStates);
				break;
			case 7:
				countyFunc(states,numStates);
				break;
			
				}
			}
		
			else {
			cout << "\nInvalid Choice ... Select Another Option ... \n\n";
			}

		}while (selection != 8);

		memClear(states, numStates); 

	return 0;
} 
