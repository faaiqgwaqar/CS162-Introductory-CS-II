#ifndef WAQARF_CIRCLE_HPP
#define WAQARF_CIRCLE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Circle : public Shape{
	private:
		float radius;
	public:
		Circle(float,string,string);
		float getRadius();
		void setRadius(float);
		float getArea(float);  
		~Circle();
};

#endif
