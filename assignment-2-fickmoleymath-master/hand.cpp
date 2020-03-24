/********************************************************
 * Filename: Hand.cpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: Contains constructors destructors accessors
 * and mutators for the hand class.
 * Input: Head files for the class initialization
 * Output: Constructs, mutates and Destructs Hand information
********************************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

/******************************************************
 * Function: Hand (constructor)
 * Description: default constructor that sets hand num
 * of cards to 0
 * Parameters: none
 * Pre-conditions: must be a class with integer ncards
 * Post-conditions: builds ncards for use
******************************************************/

Hand::Hand(){
        nCards = 0; //basic constuctor
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: Hand (Constructor parameterized)
 * Description: parametierized constructo that sets the
 * cards in a hand, passes in by ref a hand to be constructed
 * Parameters: ref of a hand
 * Pre-conditions: must be alloced hand
 * Post-conditions: builds hand for use
******************************************************/

Hand::Hand(const Hand& newHand){ //constructs on both accounts, passes in a hand
        this-> nCards = newHand.nCards;
        
	this-> cards = new Card[this->nCards];
        
	for (int i = 0; i < this-> nCards;i++) //populates for number of cards
                this->cards[i] = newHand.cards[i];
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function:Hand operator
 * Description: assignment operator performing construction
 * after initialization has already been called
 * Parameters: ref of hand
 * Pre-conditions: must be alloced hand
 * Post-conditions: builds hand for use
******************************************************/

void Hand::operator = (const Hand& newHand){
        this-> nCards = newHand.nCards;
        
	this-> cards = new Card[this->nCards];
        
	for (int i = 0; i < this-> nCards;i++) //populates for number of cards
                this->cards[i] = newHand.cards[i];
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: getHand
 * Description: accessor that will obtain cards
 * Parameters: none
 * Pre-conditions: must have hand that contains at
 * least one card
 * Post-conditions: returns data to respective function
******************************************************/

Card* Hand::getHand(){
        return cards;
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: addCard
 * Description: adds a new card to the hand by manupulating
 * current size
 * Parameters: none
 * Pre-conditions: nCards must be 0 or greater
 * Post-conditions: will allocate new space for the cards
******************************************************/

Card* Hand::addCard(){
        Card* temp;
        temp = new Card[nCards + 1];
       
	for(int i = 0; i < nCards; i++)
                temp[i] = cards[i];
        
	if (nCards > 0){
                delete[] cards;
        }
        
	return temp;
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: setCard
 * Description: sets data for the newly allocated card
 * and indexes a new card into the number of cards int
 * Parameters: card passed in
 * Pre-conditions: n/a
 * Post-conditions: num cards indexed by one, data alocd
******************************************************/

void Hand::setCard(Card newDeal){
        cards = addCard();
        cards[nCards] = newDeal;
        
	nCards++;
}

///////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: getnCards
 * Description: Accesor that can return the number
 * of cards
 * Parameters:none
 * Pre-conditions:must be in a class that contains an int
 * called ncards
 * Post-conditions: returns data to respective func
******************************************************/

int Hand::getnCards(){
        return nCards;
}

///////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: removeCard
 * Description: deallocs memory and removes a card from
 * the hand array of cards
 * Parameters: integer card to remove (index)
 * Pre-conditions: must be a card that exists in the
 * index
 * Post-conditions: the cards array in hand is shorter
 * and manipulated
******************************************************/

void Hand::removeCard(int exCard){
        nCards--;
        Card* temp = new Card[nCards];
        int j = 0;
        
	for(int i = 0; i < nCards+1;i++){
                if(i != exCard){
                        temp[j] = this->cards[i];
                        j++;
                }
        }
        
	delete[] cards;
        cards = temp;
}

////////////////////////////////////////////////////////////////////////////

/******************************************************
 * Function: ~Hand
 * Description: destructs data from the hand class
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: memory is cleared
******************************************************/

Hand::~Hand(){
        if(nCards > 0)
                delete[] cards; //bye bye mem leaks
}

///////////////////////////////////////////////////////////////////////////

