#include "student.hpp"

using namespace std;

Student::Student(){
	move = ' ';	
}

int Student::getStudentX(){
	return studentX;
}

int Student::getStudentY(){
	return studentY;
}

void Student::setStudentX(int newStudentX){
	studentX = newStudentX;
}

void Student::setStudentY(int newStudentY){
	studentY = newStudentY;
}

char Student::getMove(){
	return move;
}

void Student::setMove(char newMove){
	move = newMove;
}
