/*****************************************
 * Filename: zoo.cpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains implementation
 * of functionality of the zoo class public methods
 * used to play the zoo tycoon game
 * Input: headers 
 * Output: game functionality
*****************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "otter.hpp"
#include "sloth.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using namespace std;

/****************************************
 * Function: zoo (default)
 * Description: default constructor that
 * sets the parameters to default values
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data constructed
****************************************/

Zoo::Zoo(){
	monkeyCap = 1;
	otterCap = 1;
	slothCap = 1;
	monkeys = new Monkey[monkeyCap];
	otters = new Otter[otterCap];
	sloths = new Sloth[slothCap];
	balance = 1000000;
	profit = 0;
	monkeyCount = 0;
	otterCount = 0;
	slothCount = 0;
	payable = 0;
	monkeyBabyCount = 0;
	otterBabyCount = 0;
	slothBabyCount = 0;
}

/****************************************
 * Function: zoo (parameterized)
 * Description: parameterized constructor
 * used to set data for the specific inital
 * balance which is useful for testing methods
 * Parameters: double for balance
 * Pre-Conditions: balance must be > 0
 * Post-Conditions: data constructed
****************************************/

Zoo::Zoo(double initialBalance){
	monkeyCap = 1;
        otterCap = 1;
        slothCap = 1;
        monkeys = new Monkey[monkeyCap];
        otters = new Otter[otterCap];
        sloths = new Sloth[slothCap];
        balance = initialBalance;
        profit = 0;
        monkeyCount = 0;
        otterCount = 0;
        slothCount = 0;
	payable = 0;
	monkeyBabyCount = 0;
	otterBabyCount = 0;
	slothBabyCount = 0;
}

/****************************************
 * Function: addMonkey
 * Description: used to implement a new
 * monkey to the zoo when purchased, and manipulate
 * balance data with it
 * Parameters: Monkey instanciation
 * Pre-Conditions: monkey must be constructed
 * Post-Conditions: monkey array expanded, new monkey
 * added, balance adjusted
****************************************/

void Zoo::addMonkey(Monkey newMonkey){
	if (monkeyCount == monkeyCap){
		Monkey* temp = new Monkey[monkeyCap + 1];
		for (int i = 0;i < monkeyCap;i++)
			temp[i] = monkeys[i];
	
		
	delete [] monkeys;
	
	monkeyCap += 1;
	monkeys = temp;
	}
	
	monkeys[monkeyCount] = newMonkey;
	monkeyCount ++;
	balance -= newMonkey.getCost();
	payable += newMonkey.getCost();
}

/****************************************
 * Function: addOtter
 * Description: used to implement a new
 * otter to the zoo when purchased, and manipulate
 * balance data with it
 * Parameters: Otter instanciation
 * Pre-Conditions: otter must be constructed
 * Post-Conditions: otter array expanded, new otter
 * added, balance adjusted
****************************************/

void Zoo::addOtter(Otter newOtter){
        if (otterCount == otterCap){
                Otter* temp = new Otter[otterCap + 1];
                for (int i = 0;i < otterCap;i++)
                        temp[i] = otters[i];


        delete [] otters;
        otterCap += 1;
        otters = temp;
        }

        otters[otterCount] = newOtter;
        otterCount ++;
        balance -= newOtter.getCost();
	payable += newOtter.getCost();
}

/****************************************
 * Function: addSloth
 * Description: used to implement a new
 * sloth to the zoo when purchased, and manipulate
 * balance data with it
 * Parameters: Sloth instanciation
 * Pre-Conditions: sloth must be constructed
 * Post-Conditions: sloth array expanded, new sloth
 * added, balance adjusted
****************************************/

void Zoo::addSloth(Sloth newSloth){
        if (slothCount == slothCap){
                Sloth* temp = new Sloth[slothCap + 1];
                for (int i = 0;i < slothCap;i++)
                        temp[i] = sloths[i];


        delete [] sloths;
        slothCap += 1;
        sloths = temp;
        }

        sloths[slothCount] = newSloth;
        slothCount ++;
        balance -= newSloth.getCost();
	payable += newSloth.getCost();
}

/****************************************
 * Function: addMonkeyBabies
 * Description: add baby monkeys to the array
 * and check for adult monkeys
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns boolean, might
 * or might not add a new monkey to the array
****************************************/

bool Zoo::addMonkeyBabies(){
	bool adultMonkeysFound = false; 
	for(int i=0;i<monkeyCount;i++){
		if(monkeys[i].getAge() >= 1095){
			Monkey temp(0,0,1,200,1500);
			addMonkey(temp);
			
			cout << "A Baby Monkey Is Born!\n";
			adultMonkeysFound = true;
			break;
		}
	}
	
	return adultMonkeysFound;
}

/****************************************
 * Function: addOtterBabies
 * Description: add baby otters to the array
 * and check for adult otters
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns boolean, might
 * or might not add a new otter to the array
****************************************/

bool Zoo::addOtterBabies(){
        bool adultOttersFound = false;
        for(int i=0;i<otterCount;i++){
                if(otters[i].getAge() >= 1095){
                        Otter temp(0,0,2,100,250);
			for(int i=0; i < temp.getNumberOfBabies(); i++)
				addOtter(temp);
			
			cout << "Otter Babies Are Born!\n";
                        adultOttersFound = true;
			break;
                }
        }

        return adultOttersFound;
}

/****************************************
 * Function: addSlothBabies
 * Description: add baby sloths to add to the 
 * array
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns boolean, might
 * or might not add a new sloth to the array
****************************************/

bool Zoo::addSlothBabies(){
        bool adultSlothsFound = false;
        for(int i=0;i<slothCount;i++){
                if(sloths[i].getAge() >= 1095){
                        Sloth temp(0,0,3,50,100);
			for(int i=0; i < temp.getNumberOfBabies(); i++)
				addSloth(temp);
			
			cout << "Sloth Babies Are Born!\n";
                        adultSlothsFound = true;
			break;
                }
        }

        return adultSlothsFound;
}

/****************************************
 * Function: removeMonkey
 * Description: kills off a monkey if sick,
 * or will make the balance manipulate with
 * a payable for sickness
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns a boolean, manipulates
 * balance and removes monkeys from array
****************************************/

bool Zoo::removeMonkey(){
	if(monkeyCount == 0 || balance >= 7500){
		if(monkeyCount == 0)
			return false;
		else{
			if(monkeyBabyCount > 0){
				int sick = rand()% 1 + monkeyCount;
				
					if(sick <= monkeyBabyCount){
					cout << "Monkey Baby Is Sick, Pay Double To Heal\n";
					balance -= 15000;
					payable += 15000;
					return true;
				}
			}
			
			balance -= 7500;
			payable += 7500;
			
			cout << "Monkey is Sick!\n";
			cout << "Payed for medical fee, new balance: $" << balance << "\n";
			return true;
		}
	}
	
	else{
		cout << "A monkey was removed from the zoo. \n";
		monkeyCount --;
		Monkey* temp = new Monkey[monkeyCap - 1];
		
		for(int i = 0; i < (monkeyCap - 1); i++)
			temp[i] = monkeys[i];
		
		delete [] monkeys;
		
		monkeyCap -= 1;
		monkeys = temp;	
		
		return true;
	}
}

/****************************************
 * Function: removeOtter
 * Description: kills off otter if sick, or
 * charges the user the appropriate amount to 
 * heal it
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: otter removed, array resized,
 * balance adjusted
****************************************/

bool Zoo::removeOtter(){
        if(otterCount == 0 || balance >= 2500){
		if(otterCount == 0)
			return false;
		else{
			if(otterBabyCount > 0){
				int sick = rand()% 1 + otterCount;
				if(sick <= otterBabyCount){
					cout << "Otter Baby is Sick, Pay Double To Heal\n";
					balance -= 5000;
					payable += 5000;
					return true;
				}
			}
	
			balance -= 2500;
			payable += 2500;
			
			cout << "Otter is Sick!\n";
			cout << "Payed for medical fee, new balance: $" << balance << "\n";
        	        
			return true;
		}
	}
        
	else{
                cout << "A otter was removed from the zoo. \n";
                otterCount --;
		Otter* temp = new Otter[otterCap - 1];
		
		for(int i =0; i < (otterCap - 1); i++)
			temp[i] = otters[i];
		
		delete [] otters;
		
		otterCap -= 1;
		otters = temp;
                
		return true;
        }
}

/****************************************
 * Function: removeSloth
 * Description: removesSloth from array if
 * sick and can not pay medical fee
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: adjusts sloth array, balance
 * payable.
****************************************/

bool Zoo::removeSloth(){
        if(slothCount == 0 || balance >= 1000){
		if(slothCount == 0)
			return false;
		else{
			if(slothBabyCount > 0){
				int sick = rand()% 1 + slothCount;
				
				if(sick <= slothBabyCount){
					cout << "Sloth Baby is Sick, Pay Double To Heal\n";
					balance -= 2000;
					payable += 2000;
					return true;
				}
			}
	
			balance -= 1000;
			payable += 1000;
			
			cout << "Sloth is Sick!\n";
			cout << "Payed for medical fee, new balance: $" << balance << "\n";
               	 	
			return true;
		}
	}
        else{
                cout << "A sloth was removed from the zoo. \n";
                slothCount --;
		Sloth* temp = new Sloth[slothCap - 1];
		
		for(int i = 0; i < (slothCap - 1); i++)
			temp[i] = sloths[i];
		
		delete [] sloths;
		
		slothCap -= 1;
		sloths = temp;
                
		return true;
        }
}

/****************************************
 * Function: getMonkeys
 * Description: accessor function to get
 * monkeys from zoo class
 * Parameters: none
 * Pre-Conditions: mpme
 * Post-Conditions: data returned to accessed
 * location
****************************************/

Monkey* Zoo::getMonkeys(){
	return monkeys;
}

/****************************************
 * Function: getOtters
 * Description: accessor function to get
 * otters from zoo class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data returned to accessed location
****************************************/

Otter* Zoo::getOtters(){
        return otters;
}

/****************************************
 * Function: getSloths
 * Description:accessor function to get
 * otters from zoo class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data returned to accessed location
****************************************/

Sloth* Zoo::getSloths(){
	return sloths;
}

/****************************************
 * Function: random Event
 * Description: triggers daily random event with
 * random trigger
 * Parameters: integer (for ec, food type)
 * Pre-Conditions: food must == 1 2 or 3
 * Post-Conditions: random event will occur in
 * game
****************************************/

void Zoo::randomEvent(int food){
	int regular = rand() % 4 + 1;
	
	if(food == 2){
		if(regular == 1)
			regular = rand() % 4 + 1;
	}
	
	if(food == 3){
		if(regular != 1){
			regular = rand() % 4 + 1;
			if(regular != 1){
				regular = rand() % 4 + 1;
				if(regular != 1)
					regular = rand()% 4 + 1;
			}
		}
	}
			
	int randAnimal,randBonus;
	bool flag;

	switch (regular) {
		case 1:
			cout << "An animal in your zoo has fallen ill. \n";
			flag = false;
			randAnimal = rand()*3+1;
		
			if (randAnimal == 1){
				flag = removeMonkey();
				if(!flag)
					flag = removeOtter();
				if(!flag)
					flag = removeSloth();
				if(!flag)
					cout << "No Animals To Remove\n";
			}
			
			else if (randAnimal == 2){
                                flag = removeOtter();
				if(!flag)
					flag = removeSloth();
				if(!flag)
					flag = removeMonkey();
				if(!flag)
					cout << "No Animals To Remove\n";
                        }
			
			else {
				flag = removeSloth();
				if(!flag)
					flag = removeMonkey();
				if(!flag)
					flag = removeOtter();
				if(!flag)
					cout << "No Animals To Remove\n";
			}

			break;
		case 2:
			cout << "Your zoo attendence is experiencing a boom. \n";
			cout << "\n..........................................\n";
			for(int i=0;i<monkeyCount;i++){
				randBonus = rand() % 251 + 250;
				monkeys[i].setPayoff(monkeys[i].getPayoff() + randBonus);
				cout << "Monkey[" << i+1 << "] Generated:" << randBonus << "...\n";
			}
			cout << "............................................\n";
			break;
		case 3:
			cout << "An animal in your zoo has beem born. \n";
                        flag = false;
                        randAnimal = rand()*3+1;

                        if (randAnimal == 1){
                                flag = addMonkeyBabies();
                                if(!flag)
                                        flag = addOtterBabies();
                                if(!flag)
                                        flag = addSlothBabies();
				if(!flag)
					cout << "No Adult Animals ... No Babies\n";
                        }

                        else if (randAnimal == 2){
                                flag = addOtterBabies();
                                if(!flag)
                                        flag = addSlothBabies();
                                if(!flag)
                                        flag = addMonkeyBabies();
				if(!flag)
					cout << "No Adult Animals ... No Babies\n";
                        }

                        else {
                                flag = addSlothBabies();
                                if(!flag)
                                        flag = addMonkeyBabies();
                                if(!flag)
                                        flag = addOtterBabies();
				if(!flag)
					cout << "No Adult Animals ... No Babies\n";
                        }
			
			break;
		case 4:
			cout << "No random event occured, continue as usual. \n";
			break;
	}
}

/****************************************
 * Function: calcProfit
 * Description: calculates profit earned
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: balance, profit adjusted
****************************************/

void Zoo::calcProfit(){
		for(int i=0;i<monkeyCount;i++){
			if(monkeys[i].getAge() < 30){
				profit += (2 * monkeys[i].getPayoff());
				monkeyBabyCount++;
			}
			else
				profit += monkeys[i].getPayoff();

			if(monkeys[i].getPayoff() > 1500)
				monkeys[i].setPayoff(1500);
		}

		for(int i=0;i<otterCount;i++){
			if(otters[i].getAge() < 30){
				profit += (2 * otters[i].getPayoff());
				otterBabyCount++;
			}
			else
				profit += otters[i].getPayoff();
		}

		for(int i=0;i<slothCount;i++){
			if(sloths[i].getAge() < 30){
				profit += (2 * sloths[i].getPayoff());
				slothBabyCount++;
			}
			else
				profit += sloths[i].getPayoff();
		}
		
		balance += profit;
}

/****************************************
 * Function: incrementAge
 * Description: increments the age by day of each
 * animal and also calculates which ones are babies
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: babies calculated, balance adjusted etc.
****************************************/

void Zoo::incrementAge(){
	for(int i = 0;i < monkeyCount;i++){
		monkeys[i].setAge(monkeys[i].getAge()+1);
		balance -= monkeys[i].getBaseFoodCost();
		payable += monkeys[i].getBaseFoodCost();
	}
	for(int i = 0;i < otterCount;i++){
                otters[i].setAge(otters[i].getAge()+1);
                balance -= otters[i].getBaseFoodCost();
		payable += otters[i].getBaseFoodCost();
		
        }
	for(int i = 0;i < slothCount;i++){
                sloths[i].setAge(sloths[i].getAge()+1);
                balance -= sloths[i].getBaseFoodCost();
		payable += sloths[i].getBaseFoodCost();
        }
}

/****************************************
 * Function: setBalance
 * Description: mutator for the balance
 * variable 
 * Parameters: double
 * Pre-Conditions: must pass in a number
 * Post-Conditions: balance manipulated
****************************************/

void Zoo::setBalance(double newBalance){
	balance = newBalance;
}

/****************************************
 * Function: delete profit
 * Description: sets the profit earned to 0
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: profit is set to 0
****************************************/

void Zoo::deleteProfit(){
	profit = 0;
}

/****************************************
 * Function: getProfit
 * Description: accessor that returns the 
 * double heald in profit
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to fucntion
 * call
****************************************/

double Zoo::getProfit(){
	return profit;
}

/****************************************
 * Function: getBalance
 * Description: accessor that returns the
 * double heald in balance
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to function
 * call
****************************************/

double Zoo::getBalance(){
	return balance;
}

/****************************************
 * Function: getMonkeyCount
 * Description: accessor that returns the
 * number of monkeys in the zoo
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to function
 * call
****************************************/

int Zoo::getMonkeyCount(){
	return monkeyCount;
}

/****************************************
 * Function: getOtterCount
 * Description: accessor that returns the
 * number of otters in the zoo
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to function
 * call
****************************************/

int Zoo::getOtterCount(){
	return otterCount;
}

/****************************************
 * Function: getSlothCount
 * Description: accessor that returns the 
 * number of sloths in the zoo
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to function
 * call
****************************************/

int Zoo::getSlothCount(){
	return slothCount;
}

/****************************************
 * Function: getPayable
 * Description: returns the value held in payable
 * in the zoo class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns data to function 
 * call
****************************************/

int Zoo::getPayable(){
	return payable;
}

/****************************************
 * Function: setPayable
 * Description: mutator that manipulates the
 * value held in variable payable
 * Parameters: int
 * Pre-Conditions: must pass in a numerical
 * value
 * Post-Conditions: payable has been mutated
****************************************/

void Zoo::setPayable(int newPayable){
	payable = newPayable;
}

/****************************************
 * Function: setMokeybfc
 * Description: sets thhe monkey base
 * food cost for each monkey
 * Parameters: double
 * Pre-Conditions: none
 * Post-Conditions: monkey base food cost
 * manipulated
****************************************/

void Zoo::setMonkeybfc(double bFC){
	for(int i = 0;i < monkeyCount; i++)
		monkeys[i].setBaseFoodCost(bFC);
}

/****************************************
 * Function: setOtterbfc
 * Description: sets the otter base food
 * cost for each otter
 * Parameters: double
 * Pre-Conditions: none
 * Post-Conditions: otter base food cost
 * maipulater
****************************************/

void Zoo::setOtterbfc(double bFC){
	for(int i = 0;i < otterCount; i++)
		otters[i].setBaseFoodCost(bFC);
}

/****************************************
 * Function: setSlothbfc
 * Description: sets the sloth base food
 * cost for each sloth
 * Parameters: double
 * Pre-Conditions: none
 * Post-Conditions: sloth base food cost 
 * manipulated
****************************************/

void Zoo::setSlothbfc(double bFC){
	for(int i = 0;i < slothCount; i++)
		sloths[i].setBaseFoodCost(bFC);
}

/****************************************
 * Function: getMonkeybb
 * Description: accessor that retrieves
 * number of babies
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns int to function
 * call
****************************************/

int Zoo::getMonkeybb(){
	return monkeyBabyCount;
}

/****************************************
 * Function: getOtterbb
 * Description: accessor that retrieves
 * number of babies
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns int to function
 * call
****************************************/

int Zoo::getOtterbb(){
	return otterBabyCount;
}

/****************************************
 * Function: getSlothbb
 * Description: accessor that retireves
 * number of babies
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns int to function
 * call
****************************************/

int Zoo::getSlothbb(){
	return slothBabyCount;
}

/****************************************
 * Function: resetBabyCount
 * Description: mutator that resets the values
 * of the baby counts to 0
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: values at reset to 0
****************************************/

void Zoo::resetBabyCount(){
	monkeyBabyCount = 0;
	otterBabyCount = 0;
	slothBabyCount = 0;
}

/****************************************
 * Function: ~Zoo
 * Description: descructor for data in the
 * zoo class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: data is destructed
****************************************/

Zoo::~Zoo(){
	delete [] monkeys;
	delete [] otters;
	delete [] sloths;
}


