/**********************************
 * Filename: monkey.hpp
 * Author: faaiq waqar
 * Date: 2.18.19
 * Description: header file contianing
 * declaration for the monkey child class
 * Input: libraries
 * Output: monkey class declaration
**********************************/

#ifndef WAQARF_MONKEY_HPP
#define WAQARF_MONKEY_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monkey : public Animal{
        public:
                Monkey();
                Monkey(int newAge,
		double newCost,
		int newNumberOfBabies,
		double newBaseFoodCost,
		double newPayoff);
		~Monkey();
};

#endif
