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

Wall::Wall(){
	setBeggining(false);
	setContainer('#');
	setInstructor(false);
	setFinish(false);
	setLadder(false);
	setOccupiable();
	setProgSkill(false);
	setStudent(false);
	setTa(false);
}

bool Wall::getBeggining(){
	return isBeggining;
}

bool Wall::getInstructor(){
	return isInstructor;
}

bool Wall::getFinish(){
	return isFinish;
}

bool Wall::getLadder(){
	return isLadder;
}

bool Wall::getOccupiable(){
	return isOccupiable;
}

bool Wall::getProgSkill(){
	return isProgSkill;
}

bool Wall::getStudent(){
	return isStudent;
}

bool Wall::getTa(){
	return isTa;
}

char Wall::getContainer(){
	return container;
}

void Wall::setBeggining(bool newBeggining){
	isBeggining = newBeggining;
}

void Wall::setContainer(char newContainer){
	container = newContainer;
}

void Wall::setInstructor(bool newInstructor){
	isInstructor = newInstructor;
}

void Wall::setFinish(bool newFinish){
	isFinish = newFinish;
}

void Wall::setLadder(bool newLadder){
	isLadder = newLadder;
}

void Wall::setOccupiable(){
	isOccupiable = false;
}

void Wall::setProgSkill(bool newProgSkill){
	isProgSkill = newProgSkill;
}

void Wall::setStudent(bool newStudent){
	isStudent = newStudent;
}

void Wall::setTa(bool newTa){
	isTa = newTa;
}

Wall::~Wall(){

}
