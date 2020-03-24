#ifndef WAQARF_SHAPE_HPP
#define WAQARF_SHAPE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Shape{
	private:
		string name;
		string color;
	public:
		Shape(string,string);
		string getName();
		string getColor();
		void setName(string);
		void setColor(string);
		float getArea(float,float);
		~Shape();
};

#endif
