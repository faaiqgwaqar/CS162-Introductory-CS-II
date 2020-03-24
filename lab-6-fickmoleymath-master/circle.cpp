#include "shape.hpp"
#include "circle.hpp"

using namespace std;

Circle::Circle(float newRadius,string newName,string newColor) : Shape(newName,newColor){
	radius = newRadius;
}

float Circle::getRadius(){
	return radius;
}

void Circle::setRadius(float newRadius){
	radius = newRadius;
}

float Circle::getArea(float dim1){
	return ((dim1*dim1) * 3.14);
}

Circle::~Circle(){

}
