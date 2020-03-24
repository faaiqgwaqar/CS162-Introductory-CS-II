#include "gamerule.hpp"

using namespace std;

Card::Card(){
	rank = 0;
	suit = 0;
}

void Card::setCard(int newRank,int newSuit){
	rank = newRank;
	suit = newSuit;
}

int Card::getRank(){
	return rank;
}

int Card::getSuit(){
	return suit;
}

Card::~Card(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////

Deck::Deck(){
	nCards = 52;
	indexCards = 0;
	int i = 0;
	
	for(int j = 0;j < 4;j++){ //there are all types on the suit for each 13 numbers
		for(int k = 0; k < 13; k++){
			cards[i].setCard(k,j);
			i++; //must add each time
		}
	}
}

Card Deck::dealCard(){
	indexCards++; //once a card is gone, must index through to make sure no reuse
	return cards[indexCards-1];
}

void Deck::shuffleCard(){
	int cIND;
	int remIND = nCards-indexCards;
	
	srand(time(NULL)); //I looked this one up, but basically uses the time.h lib to shuffle
	for(int i = indexCards;i < nCards;i++){
		cIND = rand() % remIND + indexCards;
		Card temp = cards[cIND];
		cards[cIND] = cards[i];
		cards[i] = temp;
	}
}

Card Deck::getCard(int i){
	return cards[i]; //returns cards for respective index
}

Deck::~Deck(){ //basic c++ gen destructor

}

//////////////////////////////////////////////////////////////////////////////////////////////////

Hand::Hand(){
	nCards = 7; //basic constuctor
}

Hand::Hand(const Hand& newHand){ //constructs on both accounts, passes in a hand
	this-> nCards = newHand.nCards;
	this-> cards = new Card[this->nCards];
	for (int i = 0; i < this-> nCards;i++) //populates for number of cards
		this->cards[i] = newHand.cards[i];
}

Card* Hand::getHand(){
	return cards;
}

Card* Hand::addCard(){
	Card* temp;
	temp = new Card[nCards + 1];
	for(int i = 0; i < nCards; i++)
		temp[i] = cards[i];

	return temp;
}

void Hand::setCard(Card newDeal){
	cards = addCard();
	cards[nCards] = newDeal;
	nCards++;
}

int Hand::getnCards(){
	return nCards;
}

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
	cards = temp;
}

Hand::~Hand(){
	delete[] cards; //bye bye mem leaks
}

//////////////////////////////////////////////////////////////////////////////////////////////////


