/*****************************************************
 * Program Filename: ECONDATA.CPP
 * Author: FAAIQ G WAQAR
 * Date: 01.21.19
 * Description: SPECIFIC FILE USED FOR FUNCTION HOUSING
 * FOR FILE I/O ASSIGNMENT. ASSIGNMENT TAKES IN A FILE
 * AS COMMAND LINE ARG AND SORTS DATA THAT USERS CAN
 * LOOK THROUGH FOR HIGHLIGHT INFORMATION.
 * Input: INTEGERS, INFILES AND STRUCTS
 * Output: DELETION OF MEMORY LEAKS, FILE READING
*****************************************************/

#include "econdata.hpp"
using namespace std;

/****************************************************
 * Function: CREATESTATES
 * Description: ALLOCATES DYNAMIC SPACE FOR STATE
 * STRUCT
 * Parameters: TAKES IN INTEGER FROM FILE IN FOR
 * SIZE
 * Pre-Conditions: CAN ONLY OPERATE ON BASIS OF FILE
 * IN
 * Post-Conditions: RETURNS A SET ARRAY THAT IF OVER
 * DRAWN WILL RESULT IN A SEGMENTATION FAULT
****************************************************/

struct state* createStates(int n){
	struct state* states = new state[n];
	return states;
}

//////////////////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: CREATECOUNTIES
 * Description: ALLOCATES DYNAMIC SPACE FOR COUNTY
 * STRUCT
 * Parameters: TAKES IN INTEGER FROM FILE IN FOR
 * SIZE
 * Pre-Conditions: CAN ONLY OPERATE ON THE BASIS OF
 * FILE IN
 * Post-Conditions: RETURNS A SET ARRAY THAT IF OVER
 * DRAWN WILL RESULT IN A SEGMENTATION FAULT
***************************************************/

struct county* createCounties(int n){
	struct county* counties = new struct county[n];
	return counties;
}

//////////////////////////////////////////////////////////////////////////////////////

/**************************************************
 * Function: READSTATES
 * Description: USES IFSTREAM TO FILL DATA INTO
 * THE STATE STRUCT ARRAY
 * Parameters: TAKES IN STATE STRUCT ARRAY, INDEX
 * INTEGER, AND IFSTREAM PATH
 * Pre-Conditions: STATE STRUCT PATH MUST BE ALLOCATED
 * Post-Conditions: MUST BE DELETED TO ELMINATE MEM
 * LEAKAGE
**************************************************/

void readStates(struct state *s,int i,ifstream &file){
	file >> s[i].name 
	>> s[i].unemployed2007 
	>> s[i].unemployed2015 
	>> s[i].medianIncome 
	>> s[i].numCounties;
}

//////////////////////////////////////////////////////////////////////////////////////

/************************************************
 * Function: READCOUNTIES
 * Description:USES IFSTREAM TO FILL DATA INTO
 * THE COUNTY STRUCT ARRAY UNDER THE STATE DATA
 * Parameters: TAKES IN COUNTY STRUCT ARRAY, INDEX
 * INTEGER, AND IFSTRAM PATH
 * Pre-Conditions: COUNTY STRUCT MUST BE ALLOCATED
 * Post-Conditions: MUST BE DELETED TO ELIMINATE MEM
 * LEAKAGE
************************************************/

void readCounties(struct county *c,int numCounties,ifstream &file){
	for (int i = 0; i < numCounties; i++) 
		file >> c[i].name 
		>> c[i].unemployed2007 
		>> c[i].unemployed2015
		>> c[i].medianIncome;
}

//////////////////////////////////////////////////////////////////////////////////////

/***********************************************
 * Function: MEMCLEAR
 * Description: DELETES MEMORY CREATED ON THE HEAP
 * TO ELIMINATE MEMORY LEAKAGES
 * Parameters:TAKES IN STRUCT DATA AND AN INDEX
 * INTEGER
 * Pre-Conditions: MEMORY MUST FIRST EXIST ON THE
 * HEAP FOR IT TO BE DELETED
 * Post-Conditions: N/A
***********************************************/

void memClear(struct state* s,int n){
	for (int i = 0; i<n; i++)
		delete [] s[i].counties;
	delete [] s;
}

/////////////////////////////////////////////////////////////////////////////////////

/************************************************
 * Function: HIGHINCOME
 * Description: SORTS TO FIND THE STATE WITH THE
 * HIGHEST MEDIAN INCOME
 * Paramaters: STATE STRUCT ARRAY, NUMBER OF
 * STATES
 * Pre-Conditions: SELECTION ON MENU 1 MUST
 * BE SELECTED
 * Post-Conditions: N/A
************************************************/

void highIncome(struct state* states,int numStates){
	string stateName;
	float datapoint;			
	int tempIn = 0;
        stateName = states[0].name;
        for (int i = 1; i < numStates; ++i){
     		if (states[tempIn].medianIncome < states[i].medianIncome){
        		stateName = states[i].name;
                       	datapoint = states[i].medianIncome;
                        tempIn = i;
                }
        }
        cout << "\nState High Med Income ... \n";
        cout << "name: " << stateName << "\n";
        cout << "median income: " << datapoint << "\n";
}

/////////////////////////////////////////////////////////////////////////////////////

/***********************************************
 * Function: LOWINCOME
 * Description: SORTS TO FIND THE LOWEST
 * STATE INCOME AND DISPLAYS IT
 * Parameter: STATE STRUCT ARRAY AND NUMBER
 * OF STATES
 * Pre-Conditions: MUST OPERATE ON BASIS OF 
 * SELECTION OF 2 ON MAIN MENU
 * Post-Conditions:N/A
************************************************/

void lowIncome(struct state* states, int numStates){
	string stateName;
	int tempIn = 0;
        stateName = states[0].name;
        for (int i = 1; i < numStates; ++i){
        	if (states[tempIn].medianIncome > states[i].medianIncome){
                	stateName = states[i].name;
                        tempIn = i;
                }
   	}
        cout << "\nState Low Med Income ... \n";
       	cout << "name: " << stateName << "\n";
       	cout << "median income: " << states[tempIn].medianIncome << "\n";

}

/////////////////////////////////////////////////////////////////////////////////////

/**********************************************
 * Function: HIGHUNEMPLOYED
 * Description: SORTS TO FIND THE HIGHEST
 * STATE UNEMPLOYMENT RATE FOR 2015
 * Parameter: STATE STRUCT ARRAY POINTER,
 * INTEGER FOR NUMBER OF STATES
 * Pre-Conditions: MUST OPERATE ON BASIS OF
 * SELECTION OF 3 ON MAIN MENU
 * Post-Conditions: N/A
**********************************************/

void highUnemployed(struct state* states, int numStates){
	string stateName;
	float datapoint;
	int tempIn = 0;
        stateName = states[0].name;
        for (int i = 1; i < numStates; ++i){
        	if (states[tempIn].unemployed2015 < states[i].unemployed2015){
                	stateName = states[i].name;
                        datapoint = states[i].unemployed2015;
                        tempIn = i;
               	}
        }
        cout << "\nState High Unemployement 2015 ... \n";
        cout << "name: " << stateName << "\n";
        cout << "unemployed 2015: " << datapoint << "\n";
}

/////////////////////////////////////////////////////////////////////////////////////

/**********************************************
 * Function: LOWUNEMPLOYED
 * Description: SORTS TO FIND THE LOWEST
 * STATE UNEMPLOYMENT RATE FOR 2015
 * Parameters: STATE ARRAY STRUCTS, 
 * INTEGER FOR NUMBER OF STATES
 * Pre-Conditions: MUST OPERATE ON BASIS OF
 * SELECTION OF 4 ON MAIN MENU
 * Post-Conditions: N/A
 * *******************************************/

void lowUnemployed(struct state* states, int numStates){
	string stateName;
	float datapoint;
	int tempIn = 0;
       	stateName = states[0].name;
        for (int i = 1; i < numStates; ++i){
        	if (states[tempIn].unemployed2015 > states[i].unemployed2015){
                	stateName = states[i].name;
                        datapoint = states[i].unemployed2015;
                        tempIn = i;
                }
     	}
        cout << "\nState Low Unemployment 2015 ... \n";
    	cout << "name: " << stateName << "\n";
        cout << "unemployed 2015: " << datapoint << "\n";
}

////////////////////////////////////////////////////////////////////////////////////

/*************************************************
 * Function: EMPSORT
 * Description: SORTS THE ARRAY OF THE STRUCTS BY
 * THE DIFFERENCE (-) IN SUBTRACTION OF UNEMPLOYMENT
 * IN 2007 VS 2015
 * Parameters: STATE STRUCT ARRAY AND NUMBER OF STATES
 * Pre-Conditions: MUST OPERATE ON BASIS OF SELECTION
 * OF 5 ON MAIN MENU
 * Post-Conditions: ARRAY IS SORTED IN NON-ORIG FORM
**************************************************/

void empSort(struct state* states, int numStates){
	string stateName;
	for (int i = 0; i < numStates; i++){
        	for(int j = 0; j < numStates; j++){
                	if ((states[j].unemployed2007 - states[j].unemployed2015)
                       	> (states[j+1].unemployed2007 - states[j+1].unemployed2015)){
                        	struct state temp = states[j];
                                states[j] = states[j + 1];
                               	states[j+1] = temp;
                        }
               	}
       	}

       	cout << "\nStates Sorted by Change in Unemployment 2007 to 2015...\n";

        for (int i = 0; i < numStates; i++){
        cout << "name: " << states[i].name<< "\n";
        cout << "unemployement 2007: " << states[i].unemployed2007 << "\n";
       	cout << "unemployment 2015: " << states[i].unemployed2015 << "\n\n";
        }
}

///////////////////////////////////////////////////////////////////////////////////

/**************************************************
 * Function: IMPSORT
 * Description: SORTS THE ARRAY OF THE STRUCTS BY
 * THE MEDIAN INCOME OF EACH STATE
 * Parameters: STATE STRUCT ARRAY AND NUMER OF STATES
 * Pre-Conditions: MUST OPERATE ON THE BASIS OF SELECTION
 * OF 6 ON THE MAIN MENU
 * Post-Conditions: ARRAY IS SORTED IN NON-ORIG FORM
**************************************************/

void incSort(struct state* states, int numStates){
	string stateName;
	for (int i = 0; i < numStates - 1; i++){
        	for (int j = 0; j < numStates - i - 1; j++){
                	if (states[j].medianIncome < states[j+1].medianIncome){
                          	struct state temp = states[j];
                                states[j] = states[j+1];
                               	states[j+1] = temp;
                       	}
             	}
        }

        cout << "\nStates Sorted by Med Income ... \n";
       	for (int i = 0; i < numStates; i++)
        cout << "name: " << states[i].name << "| median income: " << states[i].medianIncome << "\n";

}

//////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: COUNTYFUNC
 * Description:TAKES IN A SPECIFIC STATE AND CAN PERFORM
 * ALL STATE OPERATIONS SEEN IN PREVIOUS FUNCTIONS ON THE 
 * SPECIFIC COUNTIES
 * Parameters: STATE STRUCT ARRAY CONTAINING COUNTIES
 * NUMBER OF STATES
 * Pre-Conditions: MUST OPERATE ON THE BASIS OF SELECTION OF
 * 7 ON MAIN MENU
 * Post-Conditions: MAY SORT SPECIFIC COUNTY DATA ARRAYS
****************************************************/

void countyFunc(struct state* states, int numStates){
	string stateName; //varaible decs
	float datapoint;
	int tempIn,ctselection;
 	int stateNum;
        do{ // state selection with error handling for cin crashing
        	cout << "\n Select a State: \n";
                for (int i = 0; i < numStates; i++)
                  	cout << i+0 << "." << states[i].name << "\n";

                cin >> stateNum;

		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid\n";
		}

                if (stateNum < 0 || stateNum > numStates -1)
                  	cout << "Invalid Input, Try Again ... \n";
        }while (stateNum < 0 || stateNum > numStates -1);

	// print out menu
        cout << "Menu ... \n";
      	cout << "1. Print County High Med Income ... \n";
        cout << "2. Print County Low Med Income ... \n";
       	cout << "3. Print County High Unemployment 2015 ... \n";
       	cout << "4. Print County Low Unemployment 2015 ... \n";
      	cout << "5. Print County Sorted by Change in Unemployment 2007 to 2015 ... \n";
        cout << "6. Print County Sorted by Change in Med Income ... \n";

       	cin >> ctselection;

        if(cin.fail()){
          	cin.clear();
                cin.ignore();
                cout << "Invalid\n";
        }


        if (ctselection > 0 && ctselection <= 6){

        switch(ctselection){
        	case 1: // finds the county specific high median income
                     	tempIn = 0;
                       	stateName = states[stateNum].counties[0].name;
                        for (int i = 1; i < states[stateNum].numCounties; i++){
                         	if (states[stateNum].counties[tempIn].medianIncome < 
				states[stateNum].counties[i].medianIncome){
                                  	stateName = states[stateNum].counties[i].name;
                                       	datapoint = states[stateNum].counties[i].medianIncome;
                                        tempIn = i;
                               	}
                      	}
                        cout << "County High Med Income ... \n";
                        cout << "name: " << stateName << "\n";
                        cout << "median income: " << datapoint << "\n";
                        break;
                case 2: // fincs the county specific low median income
                       	tempIn = 0;
                        stateName = states[stateNum].counties[0].name;
                        for (int i = 1; i < states[stateNum].numCounties; i++){
                       		if (states[stateNum].counties[tempIn].medianIncome >
				states[stateNum].counties[i].medianIncome){
                                	stateName = states[stateNum].counties[i].name;
                                       	datapoint = states[stateNum].counties[i].medianIncome;
                                        tempIn = i;
                                }
                        }
                        cout << "County Low Med Income ... \n";
                        cout << "name: " << stateName << "\n";
                        cout << "median income: " << datapoint << "\n";
                        break;
               	case 3: //finds the county specific high unemployment in 2015
                    	tempIn = 0;
                      	stateName = states[stateNum].counties[0].name;
                        for (int i = 1; i < states[stateNum].numCounties; i++){
                            	if (states[stateNum].counties[tempIn].unemployed2015 <
				states[stateNum].counties[i].unemployed2015){
                                     	stateName = states[stateNum].counties[i].name;
                                        datapoint = states[stateNum].counties[i].unemployed2015;
                                        tempIn = i;
                                }
                        }
                        cout << "County High Unemployment 2015 ... \n";
                        cout << "name: " << stateName << "\n";
                      	cout << "unemployed 2015: " << datapoint << "\n";
                        break;
                case 4: //finds the county specific low unemployment in 2015
                       	tempIn = 0;
                        stateName = states[stateNum].counties[0].name;
                        for (int i = 1; i < states[stateNum].numCounties; i++){
                        	if (states[stateNum].counties[tempIn].unemployed2015 > 
				states[stateNum].counties[i].unemployed2015){
                	                stateName = states[stateNum].counties[i].name;
                        	       	datapoint = states[stateNum].counties[i].unemployed2015;
                               		tempIn = i;
                        	}
                       	 }
                         cout << "County Low Unemployment 2015 ... \n";
                         cout << "name: " << stateName << "\n";
                         cout << "unemployed 2015: " << datapoint << "\n";
                         break;
                 case 5: // sorts through county data based on unemployment change
                        for (int i = 0; i < states[stateNum].numCounties -1; i++){
                           	for (int j = 0; j < states[stateNum].numCounties - i - 1; j++){
                                     	if ((states[stateNum].counties[j].unemployed2007 -
					states[stateNum].counties[j].unemployed2015) >
					(states[stateNum].counties[j+1].unemployed2007 - 
					states[stateNum].counties[j+1].unemployed2015)){
                                          	struct county tempC = states[stateNum].counties[j];
                                           	states[stateNum].counties[j] =
						states[stateNum].counties[j+1];
                                                states[stateNum].counties[j+1] = tempC;
                                  	}
                             	}
                     	}

                        cout << "County Sorted by Change in Unemployment 2007 to 2015 ... \n";
                        for (int i = 0; i < states[stateNum].numCounties; i++){
                    	   	cout << "name: " << states[stateNum].counties[i].name << "\n";
                       		cout << "unemployed 2007: " << states[stateNum].counties[i].unemployed2007 << "\n";
                     		cout << "unemployed 2015: " << states[stateNum].counties[i].unemployed2015 << "\n\n";
                       	}
                        break;
                  case 6: //sorts through county data based on median income
                       	for (int i = 0; i < states[stateNum].numCounties - 1; i++){
                         	for (int j = 0; j < states[stateNum].numCounties-i-1; j++){
                                    	if (states[stateNum].counties[j].medianIncome > 
					states[stateNum].counties[j+1].medianIncome){
                                                	struct county temp = states[stateNum].counties[j];
                                                        states[stateNum].counties[j] = states[stateNum].counties[j+1];
                                                        states[stateNum].counties[j+1] = temp;
                                        }
                             	}
                        }
                        cout << "County Sorted by Change in Median Income ... \n";
                        for (int i = 0; i < states[stateNum].numCounties; i++){
                        	cout << "name: " << states[stateNum].counties[i].name << "\n";
                                cout << "median income: " << states[stateNum].counties[i].medianIncome << "\n\n";
                     	}
		}
	}
}
