#ifndef WAQARF_SQUARE_HPP
#define WAQARF_SQUARE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Square : public Rectangle{
	public:
		Square(float,string,string);
		void setDimentions(float);
		~Square();
};

#endif
