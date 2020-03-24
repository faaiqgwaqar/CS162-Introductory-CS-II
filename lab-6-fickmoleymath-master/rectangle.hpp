#ifndef WAQARF_RECTANGLE_HPP
#define WAQARF_RECTANGLE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Rectangle : public Shape{
        private:
                float width;
                float height;
        public:
                Rectangle(float,float,string,string);
		float getWidth();
		float getHeight();
		void setWidth(float);
		void setHeight(float);
		~Rectangle();
};

#endif
