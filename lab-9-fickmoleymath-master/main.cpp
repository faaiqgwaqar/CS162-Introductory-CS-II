#include "instructor.hpp"
#include "location.hpp"
#include "level.hpp"
#include "maze.hpp"
#include "menu.hpp"
#include "open.hpp"
#include "person.hpp"
#include "student.hpp"
#include "ta.hpp"
#include "wall.hpp"

#include <unistd.h>

using namespace std;

int main(){
	Level l;
	bool endGame;

	while(endGame == false){
		l.printBoard();
		cout << "\n\n";
		l.movePlayer();
		endGame = l.checkEnd();
		sleep(1);
	}
	return 0;
}
