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

Maze::Maze(){
	levelZ = 0;

}

int Maze::getNumLevels(){
	return numLevels;
}

int Maze::getLevelX(){
	return levelX;
}

int Maze::getLevelY(){
	return levelY;
}

int Maze::getLevelZ(){
	return levelZ;
}

void Maze::setNumLevels(int newNumLevels){
	numLevels = newNumLevels;
}

void Maze::setLevelX(int newLevelX){
	levelX = newLevelX;
}

void Maze::setLevelY(int newLevelY){
	levelY = newLevelY;
}

void Maze::setLevelZ(int newLevelZ){
	levelZ = newLevelZ;
}

void Maze::printLevel(int index){
	levels[index]->printBoard();
}

Maze::~Maze(){

} 
