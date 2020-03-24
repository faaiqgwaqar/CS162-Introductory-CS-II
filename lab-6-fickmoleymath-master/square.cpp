#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"

using namespace std;

Square::Square(float newDimention, string newName, string newColor) : Rectangle(newDimention,newDimention,newName,newColor){}

void Square::setDimentions(float newDimention){
	setWidth(newDimention);
	setHeight(newDimention);
}

Square::~Square(){

}

