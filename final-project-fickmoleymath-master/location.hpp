/******************************************
 * Filename: location.hpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the declatation for
 * the parent abstract class location
 * Inputs: c libraries 
 * Outputs: usable location class declaration~
******************************************/

#ifndef WAQARF_LOCATION_HPP
#define WAQARF_LOCATION_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Location {
	private:
		bool isBeggining;
		bool isInstructor;
		bool isFinish;
		bool isLadder;
		bool isOccupiable;
		bool isProgSkill;
		bool isStudent;
		bool isTa;

		char container;
	public:
		virtual bool getBeggining() = 0;
		virtual bool getInstructor() = 0;
		virtual bool getFinish() = 0;
		virtual bool getLadder() = 0;
		virtual bool getOccupiable() = 0;
		virtual bool getProgSkill() = 0;
		virtual bool getStudent() = 0;
		virtual bool getTa() = 0;

		virtual char getContainer() = 0;
			
		virtual void setBeggining(bool) = 0;
		virtual void setContainer(char) = 0;
		virtual void setInstructor(bool) = 0;
		virtual void setFinish(bool) = 0;
		virtual void setLadder(bool) = 0;
		virtual void setOccupiable() = 0;
		virtual void setProgSkill(bool) = 0;
		virtual void setStudent(bool) = 0;
		virtual void setTa(bool) = 0;
		
};

#endif
