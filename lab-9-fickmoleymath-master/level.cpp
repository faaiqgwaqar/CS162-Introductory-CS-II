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
#include "maze_data.hpp"

using namespace std;

Level::Level(){
	char temp;
	dimentionX = MAZE_WIDTH;
	dimentionY = MAZE_HEIGHT;

	for(int i = 0; i < dimentionX; i++){
		vector<Location*> in;
		for(int j = 0; j < dimentionY; j++){
			temp = MAZE_DATA[i][j];
			if(temp == '#')
				in.push_back(new Wall);
			else if(temp == ' ')
				in.push_back(new Open(temp));
			else if(temp == '@')
				in.push_back(new Open(temp));
			else if(temp == '^')
				in.push_back(new Open(temp));
			else if(temp == '%')
				in.push_back(new Open(temp));
			
		}
		locations.push_back(in);
	}
	
	for(int i = 0; i < dimentionX; i++){
		for(int j = 0; j < dimentionY; j++){
			if (locations[i][j]->getContainer() == '@'){
				locations[i][j]->setStudent(true);
				locations[i][j]->setBeggining(true);
				s1.setStudentX(i);
				s1.setStudentY(j);
				startX = i;
				startY = j;
			}
			else if(locations[i][j]->getContainer() == '^'){
				locations[i][j]->setFinish(true);
				endX = i;
				endY = j;
			}
		}
	
	}
}

int Level::getDimentionX(){
	return dimentionX;
}

int Level::getDimentionY(){
	return dimentionY;
}

void Level::setDimentionX(int newDimentionX){
	dimentionX = newDimentionX;
}

void Level::setDimentionY(int newDimentionY){
	dimentionY = newDimentionY;
}

void Level::printBoard(){
	for(int i = 0; i < dimentionX; i++){
		for(int j = 0; j < dimentionY; j++){
			if(locations[i][j]->getStudent() == true)
				cout << "*";
			else
			cout << locations[i][j]->getContainer();
		}
	cout << "\n";
	}
	cout << "move: " << s1.getMove() << "\n";
}

void Level::movePlayer(){
	srand(time(NULL));
	bool move = false;
	int movement;
	while(move == false){
		movement = rand()%4+1;
		if(movement == 1){
			if(locations[s1.getStudentX()][s1.getStudentY() - 1]->getOccupiable() == true){
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(false);
				s1.setStudentY(s1.getStudentY()-1);
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(true);
				s1.setMove('w');
				move = true;
			}
		}
		else if(movement == 2){
			if(locations[s1.getStudentX()][s1.getStudentY() + 1]->getOccupiable() == true){
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(false);
				s1.setStudentY(s1.getStudentY()+1);
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(true);
				s1.setMove('s');
				move = true;
			}
		}
		else if(movement == 3){
			if(locations[s1.getStudentX()][s1.getStudentY() - 1]->getOccupiable() == true){
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(false);
				s1.setStudentX(s1.getStudentX()-1);
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(true);
				s1.setMove('a');
				move = true;
			}
			
		}
		else if(movement == 4){
			if(locations[s1.getStudentX()+1][s1.getStudentY()]->getOccupiable() == true){
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(false);
				s1.setStudentX(s1.getStudentX()+1);
				locations[s1.getStudentX()][s1.getStudentY()]->setStudent(true);
				s1.setMove('d');
				move = true;
		}
	}
	}
}

bool Level::checkEnd(){
	if(s1.getStudentX() == endX && s1.getStudentY() == endY)
		return true;
	return false;
}

Level::~Level(){

}
