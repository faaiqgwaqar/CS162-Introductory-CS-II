/*******************************************
 * Filename: otter.hpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains declaration of the
 * child class otter
 * Input: libraries
 * Output: class declaration
*******************************************/

#ifndef WAQARF_OTTER_HPP
#define WAQARF_OTTER_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Otter : public Animal{
        public:
                Otter();
                Otter(int newAge,
		double newCost,
		int newNumberOfBabies,
		double newBaseFoodCost,
		double newPayoff);
		~Otter();
};

#endif
