/*********************************************************
 * Filename: player.cpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: contains constructors, desructors, accessors
 * and mutators
 * Input: header files, containing instruction for the 
 * Output: Constucts, mutates and destucts player contents
*********************************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

/*******************************************************
 * Function: player (constuctor)
 * Description: constructs data for player class
 * Parameters: none
 * Pre-Conditions: must be part of a class with books
 * and number of books that can be dynamically constucted
 * Post-Conditions: constucted data can now be used
*******************************************************/

Player::Player(){
        books = new int[1];
        nBooks = 0;
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: getHand (accessor)
 * Description: getter that returns the hand of 
 * the respective player
 * Parameters: none
 * Pre-Conditions: must be part of a class that contains
 * a hand
 * Post-Conditions: returns data to respective function
*******************************************************/

Hand Player::getHand(){
        return hand;
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function:getBooks (accessor)
 * Description: getter that returns the books of a respective
 * player
 * Parameters: none
 * Pre-Conditions: must be a dynamic alloc of ints to return
 * Post-Conditions: returns data to respective function
*******************************************************/

int* Player::getBooks(){
        return books;
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: getnBooks (accessors)
 * Description: getter that returns the number of books for
 * respective player
 * Parameters: none
 * Pre-Conditions: must be in a class that contains an number
 * of books element integer
 * Post-Conditions: returns data to respective function
*******************************************************/

int Player::getnBooks(){
        return nBooks;
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: addCard
 * Description: used in order to call and add a card that
 * has been taken from gofish
 * Parameters: newcard card class entry, number for index
 * Pre-Conditions: card must work with the array parameters,
 * number must be 0 or 1
 * Post-Conditions: returns data to respective function
*******************************************************/

int Player::addCard(Card newCard,int num){
        hand.setCard(newCard);
       
	 if(num == 0)
                cout << "Obtained: " << newCard.getRank() << " ...\n";
        
	return newCard.getRank();
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: randomCard
 * Description: used so the computer can randomly sleect a card
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns and integer to index the bargain
*******************************************************/

int Player::randomCard(){
        srand(time(NULL));
        int rCard = rand() % hand.getnCards();
        
	return hand.getHand()[rCard].getRank();
}

/////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: makeHand
 * Description: creats the hand and passes in new cards
 * Parameters: address for a deck to be allocated
 * Pre-Conditions: the deck passed in must contain 7 slots
 * or more 
 * Post-Conditions:the array of hand will have data passed in
*******************************************************/

void Player::makeHand(Deck* newDeck){
        for(int i = 0;i < 7;i++)
                hand.setCard(newDeck->dealCard());
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: setHand
 * Description: sets the hand to what is passed in via
 * a function
 * Parameters: a hand is passed in
 * Pre-Conditions: n\a
 * Post-Conditions: hand is now set to data
*******************************************************/

void Player::setHand(Hand newHand){
        hand = newHand;
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: printHand
 * Description: prints the cards in a players hand
 * Parameters: none
 * Pre-Conditions: hand wont be empty
 * Post-Conditions: data printed to screen
*******************************************************/

void Player::printHand(){
        cout << "Cards in Hand: \n";
        for(int i = 0; i < hand.getnCards();i++){
        
	int indRank = hand.getHand()[i].getRank();
        int indSuit = hand.getHand()[i].getSuit();
        
	cout << indRank << "::";

        if(indSuit == 0)
                cout << "C \n";
        else if(indSuit == 1)
                cout << "D  \n";
        else if(indSuit == 2)
                cout << "H  \n";
        else if(indSuit == 3)
                cout << "S  \n";
        }
        
	cout << "\n\n";
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: setBook
 * Description: adds a book by using a temp and allocing
 * additional memory
 * Parameters: integer for the book
 * Pre-Conditions: n/a
 * Post-Conditions: array has addtional space filled with ne
 * integer
*******************************************************/

void Player::setBook(int newBook){
        int* temp = new int[nBooks+1];
        
	for (int i = 0; i < nBooks; i++)
                temp[i] = books[i];
        
	temp[nBooks] = newBook;
        nBooks++;
        
	delete[] books;
        
	books = temp;
        removeBook(newBook);
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: newHand
 * Description: allocated hand data to the adress passed in
 * Parameters: hand address
 * Pre-Conditions: must contain equal space for memory to work
 * without crash
 * Post-Conditions: sets address vals to hand
*******************************************************/

void Player::newHand(Hand* newHand){
        *newHand = hand;
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: copyHand
 * Description: used when hand needs to be constructed with
 * new data and must free old
 * Parameters: hand adress
 * Pre-Conditions: must contain equal spacing
 * Post-Conditions: sets address vals to hand
*******************************************************/

void Player::copyHand(Hand* newHand){
        hand.~Hand();
        hand = *newHand;
}

////////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: addHand
 * Description: creates additional hand
 * Parameters: card array, number of cards integer
 * Pre-Conditions: number of cards must be possitive
 * Post-Conditions: sets cards in a hand
*******************************************************/

void Player::addHand(Card* sCard,int nCards){
        for(int i = 0; i < nCards;i++)
                hand.setCard(sCard[i]);
}

///////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: removeBook
 * Description: removes cards contained in a book
 * from the respective hand
 * Parameters: newBook integer containing book nnumber
 * Pre-Conditions: newBook must be a card that exists 0-12
 * Post-Conditions: removes the card in the book from the hand
*******************************************************/

void Player::removeBook(int newBook){
        for(int i = 0; i < hand.getnCards(); i++){
                if(hand.getHand()[i].getRank() == newBook)
                        hand.removeCard(i);
        }
}

///////////////////////////////////////////////////////////////////

/*******************************************************
 * Function: ~Player (destructor)
 * Description: deletes information for books in the array
 * Parameters: none
 * Pre-Conditions: must exist in a class with array of alloc
 * books
 * Post-Conditions:clears memory
*******************************************************/

Player::~Player(){
        delete[] books;
}

//////////////////////////////////////////////////////////////////
