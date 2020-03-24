#include "shape.hpp"
#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle(float newWidth,float newHeight,string newName,string newColor) : Shape (newName,newColor){
	width = newWidth;
	height = newHeight;
}

float Rectangle::getWidth(){
	return width;
}

float Rectangle::getHeight(){
	return height;
} 

void Rectangle::setWidth(float newWidth){
	width = newWidth;
}

void Rectangle::setHeight(float newHeight){
	height = newHeight;
}

Rectangle::~Rectangle(){

}
