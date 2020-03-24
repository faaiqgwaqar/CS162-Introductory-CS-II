#include "shape.hpp"

using namespace std;

Shape::Shape(string newName,string newColor){
	name = newName;
	color = newColor;
}

string Shape::getName(){
	return name;
}

string Shape::getColor(){
	return color;
}

void Shape::setName(string newName){
	name = newName;
}

void Shape::setColor(string newColor){
	color = newColor;
}

float Shape::getArea(float dim1, float dim2){
		return (dim1 * dim2);
}

Shape::~Shape(){

}
