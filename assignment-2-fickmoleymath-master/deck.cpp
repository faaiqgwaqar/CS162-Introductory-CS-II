/*****************************************************
 * Filename: Deck.cpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: Contains contructors, destructors
 * accessors and mutators
 * Input: Header file inclusions for deck class
 * Output: initialization, mutation and destruction of
 * the deck class
*****************************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

/****************************************************
 * Function: Deck (Constructor)
 * Description: intializes values of the deck class
 * to default values
 * Parameters: none
 * Pre-Conditions: Must be part of a class named deck,
 * that has 2 integer variables and array of 52 cards
 * Post-Conditions: deck members are initialed for use
****************************************************/

Deck::Deck(){
        nCards = 52; //used for looping through the deck
        indexCards = 0; //used to remove for na index
        int i = 0;

        for(int j = 0;j < 4;j++){ //there are all types on the suit for each 13 numbers
                for(int k = 0; k < 13; k++){
                        cards[i].setCard(k,j);
                        i++; //must add each time
                }
        }
}

//////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: dealCard (mutator)
 * Description: manipulates the index and returns cards
 * in order to move them to specific hands
 * Parameters: None
 * Pre-Conditions: must be part of a class with an integer value
 * and an array of cards
 * Post-Conditions: index has been manipulated
****************************************************/

Card Deck::dealCard(){
        indexCards++; //once a card is gone, must index through to make sure no reuse
        return cards[indexCards-1];
}

//////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: shuffleCard (mutator)
 * Description: manipulates the array of cards using
 * the rand function in the ctime library
 * Parameters: none
 * Pre-Conditions: must be part of a class that contains
 * a card array and an index integer
 * Post-Conditions: ransomly shuffles the array of cards
****************************************************/

void Deck::shuffleCard(){
        int cIND; // index of cards
        int remIND = nCards-indexCards; // remainder for the shuffle

        srand(time(NULL)); //I looked this one up, but basically uses the ctime lib to shuffle
        for(int i = indexCards;i < nCards;i++){
                cIND = rand() % remIND + indexCards;
                Card temp = cards[cIND];
                cards[cIND] = cards[i];
                cards[i] = temp;
        }
}

//////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: getCard (getter)
 * Description: returns a specific card from the array
 * that is passed by a parameter
 * Parameters: single integer used to index
 * Pre-Conditions: must be an integer of greater than
 * zero and less than 52
 * Post-Conditions: simple return val
****************************************************/

Card Deck::getCard(int i){
        return cards[i]; //returns cards for respective index
}

/////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: getnCards (getter)
 * Description: returns the number of cards left
 * by taking away the index from the orig number
 * Parameters: none
 * Pre-Conditions: must be in class with two integers
 * Post-Conditions: simple return val
****************************************************/

int Deck::getnCards(){
        return nCards-indexCards;
}

/////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 * Function: ~Deck (destructor)
 * Description: desctructs memory allocated to prevent
 * memory leakages
 * Parameters: none
 * Pre-Conditions: must be part of a class
 * Post-Conditions: memory is destructed
****************************************************/

Deck::~Deck(){

}

////////////////////////////////////////////////////////////////////////////////////

