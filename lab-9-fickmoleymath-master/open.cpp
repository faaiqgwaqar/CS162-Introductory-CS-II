#include "instructor.hpp"
#include "level.hpp"
#include "location.hpp"
#include "maze.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

Open::Open(char newContainer){
	isBeggining = false;
	isInstructor = false;
	isFinish = false;
	isLadder = false;
	isProgSkill = false;
	isStudent = false;
	isTa = false;

	setContainer(newContainer);
	setOccupiable();
}

bool Open::getBeggining(){
	return isBeggining;
}

bool Open::getFinish(){
	return isFinish;
}

bool Open::getInstructor(){
	return isInstructor;
}

bool Open::getLadder(){
	return isLadder;
}

bool Open::getOccupiable(){
	return isOccupiable;
}

bool Open::getProgSkill(){
	return isProgSkill;
}

bool Open::getStudent(){
	return isStudent;
}

bool Open::getTa(){
	return isTa;
}

char Open::getContainer(){
	return container;
}

void Open::setBeggining(bool newBeggining){
	isBeggining = newBeggining;	
}

void Open::setContainer(char newContainer){
	container = newContainer;
}

void Open::setFinish(bool newFinish){
	isFinish = newFinish;
}

void Open::setInstructor(bool newInstructor){
	isInstructor = newInstructor;
}

void Open::setLadder(bool newLadder){
	isLadder = newLadder;
}

void Open::setOccupiable(){
	isOccupiable = true;
}

void Open::setProgSkill(bool newProgSkill){
	isProgSkill = newProgSkill;
}

void Open::setStudent(bool newStudent){
	isStudent = newStudent;
}

void Open::setTa(bool newTa){
	isTa = newTa;
}

Open::~Open(){

}

