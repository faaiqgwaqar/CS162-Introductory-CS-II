/***************************************
 * Filename: animal.hpp
 * Author: faaiq waqar
 * Date: 02.18.19
 * Description: contains the class declaration
 * for animal (the parent class)
 * Input: libraries
 * Output: header file with declaration to be
 * used
***************************************/

#ifndef WAQARF_ANIMAL_HPP
#define WAQARF_ANIMAL_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
	private:
		int age,numberOfBabies;
		double cost,baseFoodCost,payoff;
	public:
		Animal();
		Animal(int newAge,
		double newCost,
		int newNumberOfBabies,
		double newBaseFoodCost,
		double newPayoff);
		int getAge();
		int getNumberOfBabies();
		double getCost();
		double getBaseFoodCost();
		double getPayoff();
		void setAge(int newAge);
		void setNumberOfBabies(int newNumberOfBabies);
		void setCost(double newCost);
		void setBaseFoodCost(double newBaseFoodCost);
		void setPayoff(double newPayoff);
		~Animal();
};

#endif
