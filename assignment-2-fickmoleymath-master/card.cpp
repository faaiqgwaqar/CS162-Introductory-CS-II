/*****************************************************************
 * Filename: Card.cpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: Contains information for the use of the card class
 * containing constructors,destructors,accessors and mutators 
 * Input: Header Files, Card Class initialzers
 * Output: Constructed and Destructed Members
*****************************************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

/*****************************************************************
 * Function: Card (default Constructor)
 * Description: Fills out default information for a card setting
 * to zero for rank and suit
 * Parameters: None
 * Pre-conditions: Must be under some class called card,
 * must have members called rank and suit
 * Post-conditions: initializes members of class (can be accessed
 * for vals)
*****************************************************************/

Card::Card(){
        rank = 0;
        suit = 0;
}

///////////////////////////////////////////////////////////////////

/*****************************************************************
 * Function: setCard (setter)
 * Description: Fills out passed information to fill values for
 * card members
 * Parameters: Integer for rank, integer for suit
 * Pre-conditions: Must be part of a class that has members rank and suit
 * Post-conditions: initializes members of classed (can be accessed for 
 * values)
*****************************************************************/

void Card::setCard(int newRank,int newSuit){
        rank = newRank;
        suit = newSuit;
}

///////////////////////////////////////////////////////////////////

/*****************************************************************
 * Function: getRank (getter)
 * Description: Returns the rank of a card
 * Parameters: none
 * Pre-conditions: must have a member rank of type integer
 * Post-conditions: returns value in rank
*****************************************************************/

int Card::getRank(){
        return rank;
}

///////////////////////////////////////////////////////////////////

/*****************************************************************
 * Function: getSuit (getter)
 * Description: Returns the suit of a card
 * Parameters: none
 * Pre-conditions: must have a member suit of type integer
 * Post-conditions: returns value in suit
*****************************************************************/

int Card::getSuit(){
        return suit;
}

////////////////////////////////////////////////////////////////////

/*****************************************************************
 * Function: ~Card (destructor)
 * Description: Destructs memory in the card class
 * Parameters: none
 * Pre-conditions: must be of a class named card
 * Post-conditions: memory is cleared
*****************************************************************/

Card::~Card(){

}

///////////////////////////////////////////////////////////////////
