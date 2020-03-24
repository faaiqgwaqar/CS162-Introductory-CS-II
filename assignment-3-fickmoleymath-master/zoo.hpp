/*************************************
 * Filename: zoo.hpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the header instanciation
 * of the zoo class
 * Input: libraries
 * Output: declared zoo class
*************************************/

#ifndef WAQARF_ZOO_HPP
#define WAQARF_ZOO_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zoo{
        private:
                int monkeyCap,otterCap,slothCap,monkeyCount,otterCount,slothCount,payable;
		int monkeyBabyCount,otterBabyCount,slothBabyCount;
                double balance,profit;
                Monkey *monkeys;
                Otter *otters;
                Sloth *sloths;
        public:
               	Zoo();
		Zoo(double initialBalance);
                void addMonkey(Monkey newMonkey);
                void addOtter (Otter newOtter);
                void addSloth (Sloth newSloth);
                bool addMonkeyBabies();
                bool addOtterBabies();
                bool addSlothBabies();
                bool removeMonkey();
                bool removeOtter();
                bool removeSloth();
                Monkey* getMonkeys();
                Otter* getOtters();
                Sloth* getSloths();
                void randomEvent(int);
                void calcProfit();
                void incrementAge();
                void setBalance(double newBalance);
                void deleteProfit();
                double getBalance();
                double getProfit();
		int getMonkeyCount();
		int getOtterCount();
		int getSlothCount();
		int getPayable();
		void setPayable(int);
		void setMonkeybfc(double);
		void setOtterbfc(double);
		void setSlothbfc(double);
		int getMonkeybb();
		int getOtterbb();
		int getSlothbb();
		void resetBabyCount();
		~Zoo();
};

#endif
