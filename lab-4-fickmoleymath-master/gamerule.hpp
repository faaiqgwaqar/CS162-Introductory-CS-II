#ifndef WAQARF_GAMERULE_CPP
#define WAQARF_GAMERULE_CPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Card{
	private:
		int rank;
		int suit;
	public:
		Card();
		void setCard(int, int);
		int getRank();
		int getSuit();
		~Card();
};


class Deck{
	private:
		Card cards[52];
		int nCards;
		int indexCards;
	public:
		Deck();
		Card dealCard();
		Card getCard(int);
		void shuffleCard();
		~ Deck();		
};


class Hand{
	private:
		Card* cards;
		int nCards;
	public:
		Hand();
		Hand(const Hand&);
		Card* getHand();
		Card* addCard();
		void setCard(Card);
		int getnCards();
		void removeCard(int);
		~Hand();
};


/*
class Player{
	private:
	Hand hand;
	int* books;
	int nBooks;
	public:
}

class Game{
	private:
	Deck cards;
	Player players[2];
	public:
}
*/

#endif
