/****************************************
 * Filename: sloth.hpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the header declaration
 * for the sloth child class
 * Input: libraries
 * Output: declared sloth class
*****************************************/

#ifndef WAQARF_SLOTH_HPP
#define WAQARF_SLOTH_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sloth : public Animal{
        public:
                Sloth();
                Sloth(int newAge,
		double newCost,
		int newNumberOfBabies,
		double newBaseFoodCost,
		double newPayoff);
		~Sloth();
};

#endif
