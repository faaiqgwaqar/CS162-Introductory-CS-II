/*********************************************
 * Filename: main.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the main function 
 * for running the cpp program
 * Input: header files
 * Output: game run print to screen
*********************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

int main(){
	srand(time(NULL));
	const double monkeyCost = 15000,otterCost = 5000, slothCost = 2000;
	double baseFoodCost = 50;
	Zoo game(100000);
	int selection,foodChoice,ammt,day = 0,purchase,exit,prevDayProfit = 0;
	bool play = false;

	cout << "__________________Welcome to Zoo Tycoon_____________________\n";
	vector<string>menu{"Play Game","Exit Game"};
	selection = valmenu(menu);
	
	if(selection == 1)
		play = true;	
	
	else
		return 0;

	while(play){
		cout << "Day: " << ++day << "\n\n";
		cout << "Current Balance: $" << game.getBalance() <<"\n";
		cout << "What Type Of Feed Would You Like?\n";
		
		vector<string>menu7{"Regular","Premium","Cheap"};
		
		if (day >= 2){
			baseFoodCost *= rand() % 76 + 75;
			baseFoodCost /= 100;
			game.setMonkeybfc(4 * baseFoodCost);
			game.setOtterbfc(2 * baseFoodCost);
			game.setSlothbfc(baseFoodCost);
		}
		
		foodChoice = valmenu(menu7);
		
		if(foodChoice == 2){
			game.setMonkeybfc(8 * baseFoodCost);
			game.setOtterbfc(4 * baseFoodCost);
			game.setSlothbfc(2 * baseFoodCost);
		}
		
		else if(foodChoice == 3){
			game.setMonkeybfc(2 * baseFoodCost);
			game.setOtterbfc(baseFoodCost);
			game.setSlothbfc(baseFoodCost / 2);
		}
		game.incrementAge();	
		game.randomEvent(foodChoice);
		game.resetBabyCount();
		game.calcProfit();
		
		cout << "Would you like to add an adult animal? \n";
		vector<string>menu5{"Yes","No"};
		selection = valmenu(menu5);
	
		if (selection == 1){
			cout << "What kind of animal would you like? \n";
			vector<string>menu6{"Monkey","Otter","Sloth"};
			purchase = valmenu(menu6);
			
			cout << "How Many?\n";
			vector<string>menu8{"One","Two"};
			ammt = valmenu(menu8);
			
			if (purchase == 1){
				for(int i = 0; i < ammt; i++){
					Monkey monkeynew(1095,monkeyCost,1,4 * baseFoodCost,
					0.1*monkeyCost);
					game.addMonkey(monkeynew);
				}
			}
			
			else if (purchase == 2){
				for(int i = 0; i < ammt; i++){
					Otter otternew(1095,otterCost,2,2 * baseFoodCost,
					0.05*otterCost);
        	                	game.addOtter(otternew);
				}
			}
			
			else if (purchase == 3){
				for(int i = 0; i < ammt; i++){
					Sloth slothnew(1095,slothCost,3,baseFoodCost,
					0.05 * slothCost);
                   	    		game.addSloth(slothnew);
				}
			}
		}
		
			
			cout << "Your Zoo Has:\nMonkeys: " << game.getMonkeyCount() << "\n";
			cout << game.getMonkeybb() << " Are Monkey Babies.\n\n";
			cout << "Otters: " << game.getOtterCount() << "\n";
			cout << game.getOtterbb() << " Are Otter Babies. \n\n";
			cout << "Sloths: " << game.getSlothCount() << "\n";
			cout << game.getSlothbb() << " Are Sloth Babies. \n\n";			
	

			cout << "Profit For Day: " << day << " ... $" << game.getProfit() - prevDayProfit << "\n";
			prevDayProfit = game.getProfit();
			cout << "Payables For Day: " << day << " ... $" << game.getPayable() << "\n\n";
			game.setPayable(0);

			cout << "Would you like to keep playing?\n";
			exit = valmenu(menu5);
			cout <<" \n......................................................\n";
			
			if(exit == 2){
				cout << "Final Balance: $" << game.getBalance() << "\n";
				play = false;
			}

			else if(game.getBalance() <= 0){
				cout << "You are all out of money! GAME OVER. \n";
				play = false;
			}

		
	}
		
	return 0;
}
