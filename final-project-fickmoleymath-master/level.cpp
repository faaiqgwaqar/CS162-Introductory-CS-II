/***********************************************
 * Filename: level.cpp
 * Date: 3/20
 * Author: faaiq waqar
 * Description: contains the class implementation for
 * thhe level class, containing the maze and its elements
 * Inputs: all header files in the program
 * Outputs: usable function definitions for public methods
 * of the maze class
***********************************************/

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

/**********************************************
 * Function: level
 * Description: level is the constuctor for the maze class,
 * here, we will create our 2d vector, and allocate the internals
 * with the use of file io. 
 * Parameters: infile path used for reading,integers for dimentions
 * from the maze calss, which will receave and read first
 * PreConditions: file path must be validated, dimentions can not
 * be less than 1
 * PostConditions: vector is allocated, data of the members are set,
 * and other private members are set to their default values
**********************************************/

Level::Level(ifstream& infile,int newDimentionX, int newDimentionY){
	char temp;
	dimentionX = newDimentionX;
	dimentionY = newDimentionY;
	climbTime = false;
	instReset = false;

	//allocate the maze, for open class, the parameters are as follows
	//container, beggining, finish, ladder
	for(int i = 0; i < dimentionX; i++){
		vector<Location*> in;
		for(int j = 0; j < dimentionY; j++){
			infile.get(temp);
			if(temp == '#')
				in.push_back(new Wall);
			else if(temp == ' ')
				in.push_back(new Open(temp,false,false,false));
			else if(temp == '@')
				in.push_back(new Open(temp,true,false,false));
			else if(temp == '^')
				in.push_back(new Open(temp,false,false,true));
			else if(temp == '%')
				in.push_back(new Open(temp,false,true,false));
			else
				j--;
			
		}
		locations.push_back(in);
	}
	
	//now that we have a map, lets put out members onto the map
	setProgSkills();
	setTas();
	setInstructor();
	setStudent();

}

/**********************************************
 * Function: getInstReset
 * Description: accessor for inst reset, a boolean
 * that allows the program to know when to reset the
 * maze
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns boolean data held in the
 * instreset boolen
**********************************************/

bool Level::getInstReset(){
	return instReset;
}
/**********************************************
 * Function: getclimbtime
 * Description: accessor for climb time, a boolean used
 * that allows the program to know when to 
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns boolean data held in the
 * climb time boolean
**********************************************/


bool Level::getClimbTime(){
	return climbTime;
}
/**********************************************
 * Function: getinstsatisfied
 * Description: checks the instructor member
 * to see if the instructor is satisfied, providing
 * a boolean yes or no
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns boolean data from the
 * instructor held inthe intstructor satisfies boolean
**********************************************/


bool Level::getInstSatisfied(){
	return INST->getSatisfied();
}
/**********************************************
 * Function: gettaappeasement
 * Description: checks the ta class to see if
 * the ta on the map is appeased at the moment
 * using a timer
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns integer data held in the 
 * appeasement time in the ta to the function call
**********************************************/


int Level::getTaAppeasement(){
	return TA1->getAppeasedTime();	
}
/**********************************************
 * Function getstudprogskills:
 * Description: accessor that obtains the number of
 * programming skills that the student has obtained
 * Parameters: none
 * PreConditions: none
 * PostConditions: returns the integer data held in
 * the skills obtained integer held by the student
**********************************************/


int Level::getStudProgSkills(){
	return STUD->getSkillsObtained();
}
/**********************************************
 * Function: getdimentionx
 * Description: accessor that obtains the dimention
 * data of how many colums the maze has
 * Parameters: none
 * PreConditions: none 
 * PostConditions:returns ineger data held in 
 * dimention x ti the function call
**********************************************/


int Level::getDimentionX(){
	return dimentionX;
}
/**********************************************
 * Function: getdimentiony
 * Description: accessor that obtaind the dimention
 * data of how many rows the maze has
 * Parameters: none
 * PreConditions: none 
 * PostConditions: returns the intger data held in
 * the dmention y to the function call
**********************************************/


int Level::getDimentionY(){
	return dimentionY;
}
/**********************************************
 * Function: setstudprogskills
 * Description: used to mutate the value of the 
 * number of programmmig skills the intrepid student
 * has
 * Parameters: integer newSet
 * PreConditions: newSet can not be less than 0
 * PostConditions: the abount of skills obtained by
 * the student will be manipulated
**********************************************/


void Level::setStudProgSkills(int newSet){
	STUD->setSkillsObtained(newSet);
}
/**********************************************
 * Function: setdimentionx
 * Description: mutates the value of the fimention
 * x whils holds the ammount of cols
 * Parameters: integer newdimention
 * PreConditions: dimentions can not be less than 1
 * PostConditions: dimention x integer will be modified
 * into the value of newdimentionx
**********************************************/


void Level::setDimentionX(int newDimentionX){
	dimentionX = newDimentionX;
}
/**********************************************
 * Function: setdimentiony
 * Description: mutates the value of the function
 * y while hoels the ammount of rows
 * Parameters: integer newdimy
 * PreConditions: dimantions can not be less than 1
 * PostConditions: dimentiony intetger will be modifed
 * into the calue of the newdimentiony
**********************************************/


void Level::setDimentionY(int newDimentionY){
	dimentionY = newDimentionY;
}
/**********************************************
 * Function: printboard
 * Description: prints the board onto the screen
 * Parameters: none 
 * PreConditions: the board must first be alloc,
 * otherwise seg fault
 * PostConditions: board printed to system
**********************************************/


void Level::printBoard(){
	for(int i = 0; i < dimentionX; i++){
		for(int j = 0; j < dimentionY; j++){
			//student will override in the print
			if(locations[i][j]->getStudent() == true)
				cout << "*";
			else
				cout << locations[i][j]->getContainer();
		}
	cout << "\n";
	}
}
/**********************************************
 * Function:setprogskills
 * Description: this function will randomly find locaiton
 * ont he map to place the programming skills and will test
 * nearby bounds to ensure it soesnt get in the way of any
 * Parameters: none
 * PreConditions: the maze must first be alloced
 * PostConditions: board will have 3 prog skills plaed
**********************************************/

void Level::setProgSkills(){
	srand(time(NULL));
	int setX,setY;
	bool set = false;
	
	//loop while it hasnt found a spot to place it, and then break loop when it does
	//programming skill one
	while (set == false){
		setX = rand()%dimentionX;
		setY = rand()%dimentionY;
		if(locations[setX][setY]->getOccupiable() == true &&
		locations[setX][setY]->getProgSkill() == false &&
		locations[setX][setY]->getLadder() == false &&
		locations[setX][setY]->getFinish() == false &&
		locations[setX][setY]->getBeggining() == false){
			locations[setX][setY]->setProgSkill(true);
			locations[setX][setY]->setContainer('$');
			set = true;
			
		}
	}
	
	//programming skill 2
	set = false;
	while (set == false){	
		setX = rand()%dimentionX;
		setY = rand()%dimentionY;
		if(locations[setX][setY]->getOccupiable() == true &&
		locations[setX][setY]->getProgSkill() == false &&
		locations[setX][setY]->getLadder() == false &&
		locations[setX][setY]->getFinish() == false &&
		locations[setX][setY]->getBeggining() == false){
			locations[setX][setY]->setProgSkill(true);
			locations[setX][setY]->setContainer('$');
			set = true;
			
		}
	}

	//programming skill 3
	set = false;
	while (set == false){	
		setX = rand()%dimentionX;
		setY = rand()%dimentionY;
		if(locations[setX][setY]->getOccupiable() == true &&
		locations[setX][setY]->getProgSkill() == false &&
		locations[setX][setY]->getLadder() == false &&
		locations[setX][setY]->getFinish() == false &&
		locations[setX][setY]->getBeggining() == false){
			locations[setX][setY]->setProgSkill(true);
			locations[setX][setY]->setContainer('$');
			set = true;
			
		}
	}

}
/**********************************************
 * Function: setTas
 * Description: on a random basis, will take a look
 * at the ma and place initial placemtents of dynamic
 * Ta class implementations
 * Parameters: none
 * PreConditions: maze must first be allocs
 * PostConditions: tas will be allocated and placed
 * on the map
**********************************************/


void Level::setTas(){
	srand(time(NULL));
	int setX,setY;
	bool set = false;

	//Will loop until it fins a spot that works to put the ta in
	//Ta placement 1
	while (set == false){
		setX = rand()%dimentionX;
		setY = rand()%dimentionY;
		if(locations[setX][setY]->getOccupiable() == true &&
		locations[setX][setY]->getProgSkill() == false &&
		locations[setX][setY]->getLadder() == false &&
		locations[setX][setY]->getFinish() == false &&
		locations[setX][setY]->getBeggining() == false &&
		locations[setX][setY]->getTa() == false){
			locations[setX][setY]->setTa(true);
			locations[setX][setY]->setContainer('T');
			TA1 = new Ta(setX,setY);
			set = true;
			
		}
	}

	//Ta placement 2
	set = false;
	while (set == false){
		setX = rand()%dimentionX;
		setY = rand()%dimentionY;
		if(locations[setX][setY]->getOccupiable() == true &&
		locations[setX][setY]->getProgSkill() == false &&
		locations[setX][setY]->getLadder() == false &&
		locations[setX][setY]->getFinish() == false &&
		locations[setX][setY]->getBeggining() == false &&
		locations[setX][setY]->getTa() == false){
			locations[setX][setY]->setTa(true);
			locations[setX][setY]->setContainer('T');
			TA2 = new Ta(setX,setY);
			set = true;
			
		}
	}

}
/**********************************************
 * Function: moveTas
 * Description: moves the Tas around the map on 
 * a random basis
 * Parameters: none
 * PreConditions: none
 * PostConditions: will move the tas randomly to
 * a new location
**********************************************/


void Level::moveTas(){
	//use setting variables for quick access
	int setX1 = TA1->getValX();
	int setY1 = TA1->getValY();
	int setX2 = TA2->getValX();
	int setY2 = TA2->getValY();

	bool moved = false;

	//use the ta's method for movement in order to obtaina direction
	char movable = TA1->getMove();

	//loop until a place is found, the is for the first ta
	while(moved == false){
		//account for each possible direction
		if(movable == 'd'){
			if(locations[setX1][setY1-1]->getOccupiable() == true &&
			locations[setX1][setY1-1]->getProgSkill() == false &&
			locations[setX1][setY1-1]->getLadder() == false &&
			locations[setX1][setY1-1]->getFinish() == false &&
			locations[setX1][setY1-1]->getBeggining() == false &&
			locations[setX1][setY1-1]->getTa() == false){
				locations[setX1][setY1]->setTa(false);
				locations[setX1][setY1]->setContainer(' ');
				setY1--;
				locations[setX1][setY1]->setTa(true);
				locations[setX1][setY1]->setContainer('T');
				TA1->setValY(setY1);
				moved = true;
			}
			//rather than try and call to a random again, which can be tedious and take far
			//too long, simply looping through possibilities can be just as effective
			else
				movable = 'w';
		}
		//accounting for each direction 2
		if(movable == 'w'){
			if(locations[setX1-1][setY1]->getOccupiable() == true &&
			locations[setX1-1][setY1]->getProgSkill() == false &&
			locations[setX1-1][setY1]->getLadder() == false &&
			locations[setX1-1][setY1]->getFinish() == false &&
			locations[setX1-1][setY1]->getBeggining() == false &&
			locations[setX1-1][setY1]->getTa() == false){
				locations[setX1][setY1]->setTa(false);
				locations[setX1][setY1]->setContainer(' ');
				setX1--;
				locations[setX1][setY1]->setTa(true);
				locations[setX1][setY1]->setContainer('T');
				TA1->setValX(setX1);
				moved = true;
			}
			else	
				movable = 'a';
		}
		//accounting for each direction 3
		if(movable == 'a'){
			if(locations[setX1][setY1+1]->getOccupiable() == true &&
			locations[setX1][setY1+1]->getProgSkill() == false &&
			locations[setX1][setY1+1]->getLadder() == false &&
			locations[setX1][setY1+1]->getFinish() == false &&
			locations[setX1][setY1+1]->getBeggining() == false &&
			locations[setX1][setY1+1]->getTa() == false){
				locations[setX1][setY1]->setTa(false);
				locations[setX1][setY1]->setContainer(' ');
				setY1++;
				locations[setX1][setY1]->setTa(true);
				locations[setX1][setY1]->setContainer('T');
				TA1->setValY(setY1);
				moved = true;
			}
			else
				movable = 's';
		}
		//accounting for each direction 4
		if(movable == 's'){
			if(locations[setX1+1][setY1]->getOccupiable() == true &&
			locations[setX1+1][setY1]->getProgSkill() == false &&
			locations[setX1+1][setY1]->getLadder() == false &&
			locations[setX1+1][setY1]->getFinish() == false &&
			locations[setX1+1][setY1]->getBeggining() == false &&
			locations[setX1+1][setY1]->getTa() == false){
				locations[setX1][setY1]->setTa(false);
				locations[setX1][setY1]->setContainer(' ');
				setX1++;
				locations[setX1][setY1]->setTa(true);
				locations[setX1][setY1]->setContainer('T');
				TA1->setValX(setX1);
				moved = true;
			}
			else
				movable = 'd';
		}
	}

	moved = false;
	movable = TA2->getMove();

	//now do it for the second ta ont he map, with similar method
	while(moved == false){
		if(movable == 'w'){
			if(locations[setX2][setY2-1]->getOccupiable() == true &&
			locations[setX2][setY2-1]->getProgSkill() == false &&
			locations[setX2][setY2-1]->getLadder() == false &&
			locations[setX2][setY2-1]->getFinish() == false &&
			locations[setX2][setY2-1]->getBeggining() == false &&
			locations[setX2][setY2-1]->getTa() == false){
				locations[setX2][setY2]->setTa(false);
				locations[setX2][setY2]->setContainer(' ');
				setY2--;
				locations[setX2][setY2]->setTa(true);
				locations[setX2][setY2]->setContainer('T');
				TA2->setValY(setY2);
				moved = true;
			}
			else
				movable = 'a';
		}

		if(movable == 'a'){
			if(locations[setX2-1][setY2]->getOccupiable() == true &&
			locations[setX2-1][setY2]->getProgSkill() == false &&
			locations[setX2-1][setY2]->getLadder() == false &&
			locations[setX2-1][setY2]->getFinish() == false &&
			locations[setX2-1][setY2]->getBeggining() == false &&
			locations[setX2-1][setY2]->getTa() == false){
				locations[setX2][setY2]->setTa(false);
				locations[setX2][setY2]->setContainer(' ');
				setX2--;
				locations[setX2][setY2]->setTa(true);
				locations[setX2][setY2]->setContainer('T');
				TA2->setValX(setX2);
				moved = true;
			}
			else
				movable = 's';
		}

		if(movable == 's'){
			if(locations[setX2][setY2+1]->getOccupiable() == true &&
			locations[setX2][setY2+1]->getProgSkill() == false &&
			locations[setX2][setY2+1]->getLadder() == false &&
			locations[setX2][setY2+1]->getFinish() == false &&
			locations[setX2][setY2+1]->getBeggining() == false &&
			locations[setX2][setY2+1]->getTa() == false){
				locations[setX2][setY2]->setTa(false);
				locations[setX2][setY2]->setContainer(' ');
				setY2++;
				locations[setX2][setY2]->setTa(true);
				locations[setX2][setY2]->setContainer('T');
				TA2->setValY(setY2);
				moved = true;
			}
			else
				movable = 'd';
		}
		if(movable == 'd'){
			if(locations[setX2+1][setY2]->getOccupiable() == true &&
			locations[setX2+1][setY2]->getProgSkill() == false &&
			locations[setX2+1][setY2]->getLadder() == false &&
			locations[setX2+1][setY2]->getFinish() == false &&
			locations[setX2+1][setY2]->getBeggining() == false &&
			locations[setX2+1][setY2]->getTa() == false){
				locations[setX2][setY2]->setTa(false);
				locations[setX2][setY2]->setContainer(' ');
				setX2++;
				locations[setX2][setY2]->setTa(true);
				locations[setX2][setY2]->setContainer('T');
				TA2->setValX(setX2);
				moved = true;
			}
			else
				movable = 'w';
		}
	}
}
/**********************************************
 * Function: setinstuctor
 * Description: allocates an instructor onto the map
 * level (if there is one that is)
 * Parameters: none
 * PreConditions: maze must be allocaed 
 * PostConditions: an instrucotr may be instancated
 * for the level and given a coordinate system
**********************************************/


void Level::setInstructor(){
	for(int i = 0; i < dimentionX; i++){
		for(int j  = 0; j < dimentionY; j++){
			//check the container for the endgame symbol
			if(locations[i][j]->getContainer()  == '%')
				INST = new Instructor(i,j);
		}
	}
}
/**********************************************
 * Function: setstudent
 * Description: allocated a student onto the mao
 * level at the start pos "@"
 * Parameters: none
 * PreConditions: maze must be alloced
 * PostConditions: a student is instanciated for the
 * level at rhe start, and given a coordinate system
**********************************************/


void Level::setStudent(){
	for(int i = 0; i < dimentionX; i++){
		for(int j = 0; j < dimentionY; j++){
			//searches for the start symbol
			if(locations[i][j]->getContainer() == '@'){
				STUD = new Student(i,j);
				locations[i][j]->setStudent(true);
			}
		}
	}
}
/**********************************************
 * Function: studnemove
 * Description: takes in data from the move obtain
 * ment function int he student class, and tanslats
 * that into an in game move
 * Parameters: none
 * PreConditions: none 
 * PostConditions: the student will preforma  specific
 * fucntion based on the input
**********************************************/


void Level::studentMove(){
	int setX = STUD->getValX();
	int setY = STUD->getValY();
	
	bool moved = false;
	//becase the turn basis is ran every round, it makes it easy
	//to fit in incrmeenters
	incrementTaAppeased();

	//loops until the input is something that works in game
	//as it may be a valid command, but doesnt work contextually
	while(moved == false){
		//uses the student get move function
		char studChoice = STUD->getMove();
		//move left
		if(studChoice == 'a' || studChoice == 'A'){
			if(locations[setX][setY-1]->getOccupiable() == true){
				locations[setX][setY]->setStudent(false);
				setY--;
				locations[setX][setY]->setStudent(true);
				STUD->setValY(setY);
				moved = true;
			}
			//and if you cant move there
			else
				cout << "You Can't Move There!\n";
		}
		//move up
		else if(studChoice == 'w' || studChoice == 'W'){
			if(locations[setX-1][setY]->getOccupiable() == true){
				locations[setX][setY]->setStudent(false);
				setX--;
				locations[setX][setY]->setStudent(true);
				STUD->setValX(setX);
				moved = true;
			}
			else
				cout << "You Can't Move There!\n";
		}
		//move right
		else if(studChoice == 'd' || studChoice == 'D'){
			if(locations[setX][setY+1]->getOccupiable() == true){
				locations[setX][setY]->setStudent(false);
				setY++;
				locations[setX][setY]->setStudent(true);
				STUD->setValY(setY);
				moved = true;
			}
			else
				cout << "You Can't Move There!\n";
		}
		//move down
		else if(studChoice == 's'|| studChoice == 'S'){
			if(locations[setX+1][setY]->getOccupiable() == true){
				locations[setX][setY]->setStudent(false);
				setX++;
				locations[setX][setY]->setStudent(true);
				STUD->setValX(setX);
				moved = true;
			}
			else
				cout << "You Can't Move There!\n";
		}
		//climbing the ladder
		else if(studChoice == 'u' || studChoice == 'U'){
			if(STUD->getCanClimb() == true){
				//use a vairable to indicate to the maze
				//to incrmeent which level
				climbTime = true;
				cout << "Climbing The Ladder\n";
				moved = true;
			}
			else if(STUD->getCanClimb() == false)
				cout << "Can't Climb Here!\n";
		}
		//demo a programming skill
		else if(studChoice == 'p' || studChoice == 'P'){
			if(STUD->getSkillsObtained() > 0){
				TA1->setAppeasedTime(10);
				TA2->setAppeasedTime(10);
				TA1->setAppeased(true);
				TA2->setAppeased(true);
				STUD->setSkillsObtained((STUD->getSkillsObtained() - 1 ));
				moved = true;
			}
			else{
				cout << "No Skills To Demonstrate!\n";
			}
		}
	}
	
}
/**********************************************
 * Function: incrementtaappeased
 * Description: checks to see if the tas are appeased
 * in the first place, and increments the appeasement
 * on its basis
 * Parameters: none 
 * PreConditions: Tas must be alloced
 * PostConditions: the ta appeasement data miht be incremented
**********************************************/


void Level::incrementTaAppeased(){
	if(TA1->getAppeasedTime() > 0){
		//deletes by one for each move
		TA1->incrementAppeased();
		TA2->incrementAppeased();
		//check in order to reset the boolean
		if(TA1->getAppeasedTime() == 0){
			TA1->setAppeased(false);
			TA2->setAppeased(false);
		}
	}
}
/**********************************************
 * Function: studentencounter
 * Description: gives us data on what happes if
 * the student comes in contact with an action that
 * modifies the way the game plays
 * Parameters: none
 * PreConditions: none
 * PostConditions: will notify and modify the class
 * methods based on the proximity of factors near
 * the student
**********************************************/


void Level::studentEncounter(){
	//create easy to use temp variables
	int checkX = STUD->getValX();
	int checkY = STUD->getValY();
	
	//begin by checking for programmins skills
	if(locations[checkX][checkY]->getProgSkill() == true){
		//give the student another skill
		STUD->setSkillsObtained((STUD->getSkillsObtained()+1));
		//reset the place
		locations[checkX][checkY]->setProgSkill(false);
		locations[checkX][checkY]->setContainer(' ');
		cout << "SKILL OBTAINED\n";
	}
	
	//check if the student is in the ladder location
	if(locations[checkX][checkY]->getLadder() == true){
		STUD->setCanClimb(true);
	}
	else if(locations[checkX][checkY]->getLadder() == false){
		STUD->setCanClimb(false);
	}
	
	//check if the TA is near or ont he student spot "ajacency"
	if(locations[checkX][checkY]->getTa() == true ||
	locations[checkX+1][checkY]->getTa() == true ||
	locations[checkX-1][checkY]->getTa() == true ||
	locations[checkX][checkY+1]->getTa() == true ||
	locations[checkX][checkY-1]->getTa() == true){
		if(TA1->getAppeased() == false){
			resetEncounter();
			cout << "Encountered The TA ... Time For A Reset\n";
		}
		else if(TA1->getAppeased() == true)
			cout << "Encountered The TA ... But The TA is Appeased\n";
	}

	//check if the Instructor is near the student to activate endgame
	if(locations[checkX+1][checkY]->getInstructor() == true ||
	locations[checkX-1][checkY]->getInstructor() == true ||
	locations[checkX][checkY-1]->getInstructor() == true ||
	locations[checkX][checkY+1]->getInstructor() == true){
		cout <<"You Have Encountered The Instructor!\n";
		if(STUD->getSkillsObtained() < 3){
			cout << "You Don't Have Enough Skills To Pass The Course ... Reset\n";
			cout << "Press Any Move to Begin on Reset Map\n";
			instReset = true;
		}
		else{
			cout << "Congratulations, You Have Passed CS!\n";
			INST->setSatisfied(true);
			
		}
	}
}
/**********************************************
 * Function: setinstreset
 * Description: mutator that mutated boolean data
 * int eh instreset boolean, which allowsa for the 
 * entire map reset
 * Parameters: bool new inst reset
 * PreConditions: bool must be true or false
 * PostConditions: inst reset is modified to be the
 * parameter
**********************************************/


void Level::setInstReset(bool newInstReset){
	instReset = newInstReset;
}
/**********************************************
 * Function: setclimbtime
 * Description: mutator that mutates the boolean
 * data held in climb time, used to determine
 * if the person can climb
 * Parameters: boolean newclimbtime
 * PreConditions: must be true or false
 * PostConditions: climbtime boolean is mutated into
 * the newclimbtime
**********************************************/


void Level::setClimbTime(bool newClimbTime){
	climbTime = newClimbTime;
}
/**********************************************
 * Function:resetencounter
 * Description: if the map elements need to be
 * reset and reconstructed, this is the place to
 * go
 * Parameters: none
 * PreConditions: none 
 * PostConditions: resets the map elements to new
 * locations for reasons by rhe call
**********************************************/


void Level::resetEncounter(){
	//temporary vals
	int resX = STUD->getValX();
	int resY = STUD->getValY();
	STUD->setSkillsObtained(0);
	locations[resX][resY]->setStudent(false);
	setStudent();

	//for loop used to check to reset
	for(int i = 0; i < dimentionX; i++){
		for(int j = 0; j < dimentionY; j++){
			if(locations[i][j]->getProgSkill()){
				locations[i][j]->setProgSkill(false);
				locations[i][j]->setContainer(' ');
			}
			if(locations[i][j]->getTa()){
				locations[i][j]->setTa(false);
				locations[i][j]->setContainer(' ');
			}
		}
	}
		
	//use set functions
	setProgSkills();
	setTas();
	
}
/**********************************************
 * Function: ~Level
 * Description: destructor of the level class
 * Parameters: none
 * PreConditions: none
 * PostConditions: deallocates the data in the level class
**********************************************/


Level::~Level(){

}
