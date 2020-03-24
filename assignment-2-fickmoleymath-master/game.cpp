/****************************************************
 * Filename: game.cpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: contains constructors, destructors
 * accessors and mutators for the game class
 * Input: Header files, specfically the game header
 * Output: construction, mutation and destruction fo
 * the game class
****************************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

/***************************************************
 * Function: Game (constructor)
 * Description: constructs information for game class
 * in default
 * Parameters: none
 * Pre-Conditions: must have specified variables and be
 * part of a class
 * Post-Conditions: contructed information can now be used
**************************************************/

Game::Game(){
        endGame = false;
        decks = new Deck;
       
	 decks -> shuffleCard();
        
	players[0].makeHand(decks);
        players[1].makeHand(decks);
}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: playerTurn (mutator)
 * Description: when it is time for the user (player)
 * to play, the player turn will run through this function
 * Parameters: integer for indexing
 * Pre-Conditions: index integer must be a 0 or a 1
 * Post-Conditions: may (or not) manipulate the player hand, returns true or false
**************************************************/

bool Game::playerTurn(int i){
        cout << "Player Turn ... \n"; 
        
	if(players[i].getHand().getnCards() == 0){ //default go fish if the player is now out of card
                cout << "Empty Hand ... Go Fish ... \n";
                goFish(i);
        }

        this->playerStatus(i); // calls to playerstatus in order to give player information
        
	cout << "Search For What Card? ... \n";
        
	int search = isGood(i); //calls to isgood to look for a valid card
        
	cout << "\nSearched For ... " << search << "\n";
        cout << "Opponent Had ... " << handSearch(!i,search) << "\n\n";
        
	if (handSearch(!i,search) == 0) { //use this when you didnt pick a valid card from the cp
                cout << "Go Fish ...\n\n";
                int fish = goFish(i);
                if (fish == search)
                        return true;
        }
	else{
                takeCards(i,search,handSearch(!i,search)); //use this when you chose a valid card
                return true;
        }

        return false;
}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: computerturn (mutator)
 * Description: runs through during computer turn
 * Parameters: integer for index
 * Pre-Conditions: integer must be a 0 or a 1
 * Post-Conditions: May (or may not) manipulate the player hand
**************************************************/

bool Game::computerTurn(int i){
        cout << "Computer Turn ... \n";
        	
	int search = players[i].randomCard(); //uses the random card function for computer
        
	cout << "\nComputer Seached For ... " << search << "\n";
        cout << "Player has ... " << handSearch(!i,search) << "\n";
        
	if(handSearch(!i,search) == 0){ //if the card is not in the hand
                int fish = goFish(i);
                if(fish == search){
                        cout << "Computer Drew ..." << search << "\n";
                        return true;
                }
        }
        else{
                takeCards(i,search,handSearch(!i,search)); //if it is in the hand
                return true;
        }

        return false;
}

///////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: playerBase (mutator)
 * Description: creates flow of turns and can terminate game
 * Parameters: none
 * Pre-Conditions: other functions must exist to be called to
 * Post-Conditions: returns a true or false for continuation
 * of the game
**************************************************/

bool Game::playerBase(){
        bool turn = true;
        
	while (turn) {
                turn = this -> playerTurn(0);
                this -> playerBooks(0);
                this -> playerStatus(0);
                if(players[0].getnBooks()+players[1].getnBooks() == 13)
                        return true;
        }
        
	return false;
}

//////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: computerBase (mutator)
 * Description: creates flow of computer turns and can
 * terminate the game
 * Parameters:none
 * Pre-Conditions:other functions must exist to be called to
 * Post-Conditions: return a true or false for continuation
 * of the game
**************************************************/

bool Game::computerBase(){
        bool turn = true;
        
	while(turn){
                turn = this -> computerTurn(1);
                this -> playerBooks(1);
                cout << "Computer Books ... " << players[1].getnBooks() << ". \n";
                if(players[0].getnBooks()+players[1].getnBooks() == 13);
                        return true;
        }
        
	return false;
}

///////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: isGood
 * Description: used for search, indicates if a proppor
 * card has been selected (or not)
 * Parameters: integer for indexing
 * Pre-Conditions: must be an integer 1 or 0
 * Post-Conditions: returns a valid integer
**************************************************/

int Game::isGood(int i){
        bool bad = true;
        string temp;
        
	while(bad){ //loops until bad is set to falso
                cin >> temp;
                if(handSearch(i,atoi(temp.c_str())) == 0)//searches the temp for the string
                        cout << "Invalid ... Try Again\n"; //string easier for error handling
                else
                        bad = false;
        }
        
	return atoi(temp.c_str());

}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: handSearch
 * Description: does what it says, searched the hand for
 * a card
 * Parameters: integer for indexing, integer for what to
 * search for
 * Pre-Conditions: index must be 0, or 1, search must be 0 -12
 * Post-Conditions: returnsseach index integer
**************************************************/

int Game::handSearch(int i,int search){
        int searchI = 0;
        Hand* temp = new Hand;
        
	this -> players[i].newHand(temp);
        
	for(int j = 0 ; j < temp -> getnCards();j++){ //sorts through using the temp
                if(search == temp->getHand()[j].getRank()){ // in order to avoid manip of the
                        searchI++; //original while indexing values
                }
        }

        delete temp;
        return searchI;
}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: gofish
 * Description: used to go fish (get a card from deck)
 * for a respective player
 * Parameters: integer index for players
 * Pre-Conditions: the integer index mst be a 0 or a 1
 * Post-Conditions: returns an integet for card
**************************************************/

int Game::goFish(int i){
        int fish = players[i].addCard(decks->dealCard(),i);
        return fish;
}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: Printhand (getter?)
 * Description:just calls to the player class to 
 * print hand
 * Parameters: integer index for player
 * Pre-Conditions: must pass in integer of 0 or 1
 * Post-Conditions: function call, so n/a?
**************************************************/

void Game::printHand(int i){
        players[i].printHand();
}

////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function:startGame (mutator)
 * Description: starts, flows, and ends the game (control)
 * Parameters:none
 * Pre-Conditions: functions must be part of class to be called
 * Post-Conditions: game will run through
**************************************************/

void Game::startGame(){
        cout << "Welcome To Go Fish ... \n";
        playerRules();
        
	while(!endGame){
                playerBase();
                cout << "Cards Left In Deck ... " << decks->getnCards() << "\n";
                cout << "\n\n............................................................\n\n";
                computerBase();
                cout << "\n\n............................................................\n\n";
        }

        if(players[0].getnBooks() > players[1].getnBooks())
                cout << "Player Won With This Many Books ... " << players[0].getnBooks() << "\n";
        else
                cout << "Computer Won With This Many Books ... " << players[1].getnBooks() << "\n";
}

//////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: playerStatus
 * Description: rolls through what is going on with the player
 * and current status
 * Parameters: integer for player index
 * Pre-Conditions: integer must be 0 or 1
 * Post-Conditions: information about the player is printed
**************************************************/

void Game::playerStatus(int i){
        cout << "Player Hand Is ... \n";
        this -> printHand(i);
        
	cout << "Player Has ... " << players[i].getnBooks() << " Books ... \n";
        
	if(players[i].getnBooks() > 0){
                cout << "Player Books Are ...";
                for (int j = 0; j < players[i].getnBooks();j++){
                        cout << players[i].getBooks()[j] << " ";
                }
        cout << "\n\n";
        }
}

///////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: computerStatus
 * Description: I was going to do this until I realized we 
 * dont care about the computer hand. I am going to leave this
 * in anyways
 * Parameters: 
 * Pre-Conditions:
 * Post-Conditions:
**************************************************/

void Game::computerStatus(int i){

}

//////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: takeCards
 * Description: function used to take cards from one
 * player to another
 * Parameters: index integer, search integer,
 * number of cards integer
 * Pre-Conditions: index must be 1 or 0
 * search must be between 0-12 and number of cards 
 * must be greater than 0
 * Post-Conditions: manipulated hands
**************************************************/

void Game::takeCards(int i,int search,int nCards){
        Hand* temp = new Hand; 
        players[!i].newHand(temp);
        Card* take = new Card[nCards];
        int j = 0;
        
	for(int k = 0; k < temp->getnCards();k++){
                if(search == temp->getHand()[k].getRank()){
                        take[j] = temp->getHand()[k];
                        j++;
                        temp->removeCard(k);
                        k--;
                }
        }
        
	players[!i].copyHand(temp);
        players[i].addHand(take,nCards);
        delete[] take;
        delete temp;
}

///////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: playerBooks
 * Description: stores the books the players
 * Parameters: integer for player index
 * Pre-Conditions: must be a 1 or 0 on the int
 * Post-Conditions:calls to setbooks and manips hands
**************************************************/

void Game::playerBooks(int i){
        for(int j = 0;j < 13;j++){
                if(handSearch(i,j) == 4){
                        players[i].setBook(j);
                        if (i == 0)
                                cout << "Player Created Book of ... " << j << "\n\n";
                        else
                                cout << "Computer Created Book of ... " << j << "\n\n";
                }

        }
}

////////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: playerRules
 * Description: prints the rules of the game
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: prints information
**************************************************/

void Game::playerRules(){
        cout << "------------- Rules Of Go Fish ------------\n\n";
        cout << "The deck of cards is shuffled, randomizing the order of the cards.\n";
        cout << "Each player is dealt a hand of 7 cards. Only the player is able to see the cards in their hand.\n";
        cout << "The remaining cards are placed face-down (i.e. with their rank";
        cout << " and suit hidden) on the table to form the 'stock'\n";
        cout << "One of the players (player A) begins the game by asking the other player (player B) ";
        cout << "for all of his/her cards of a specific rank \n";
        cout << "(e.g. 'Please give me all of your 7's'). To ask for a given rank,";
        cout << " a player must have at least one card of that rank in his/her \nhand.";
        cout << "If player B has cards of the requested rank, he/she must ";
        cout << "give all of his/her cards of that rank to player A, and player A \ngets to take another turn.";
        cout << "If player B does not have any cards of the requested \nrank, he/she says 'go fish',";
        cout << "and player A must select one card from the stock. If that card has the rank player";
        cout << " A originally requested, \nthen player A gets to take another turn.\n";
        cout << "Otherwise, it becomes player B's turn.\n";
        cout << "If at any point a player runs out of cards, then, when it is that player's";
        cout << " turn to play, they may draw a card from the stock \nand ask for cards of that ";
        cout << "rank. If a player runs out of other cards when it is the other player's turn to";
        cout << " ask for a rank, \nthe other player may continue to ask for a rank and draw from";
        cout << " the stock until they draw a rank other than the one they asked\n for.\n";
        cout << "If a player collects all four cards of the same rank, this is called a";
        cout << " 'book', and the player lays down his/her book on the \ntable. Both players";
        cout << " may see the cards in every book that's laid down.\n";
        cout << "The game continues with the players alternating turns until all";
        cout << " of the books are laid down. At the end of the game, the player";
        cout << " \nwho laid down the most books wins.\n\n";
}

/////////////////////////////////////////////////////////////////////////////////

/***************************************************
 * Function: ~Game (destructor)
 * Description: deletes information to prevent 
 * memleaks
 * Parameters:none
 * Pre-Conditions:must have a decks in class
 * Post-Conditions: memory cleared
**************************************************/

Game::~Game(){
        delete decks;
}

/////////////////////////////////////////////////////////////////////////////////
