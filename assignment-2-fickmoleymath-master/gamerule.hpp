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
		int getnCards();
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
		void operator = (const Hand&);
		void setCard(Card);
		int getnCards();
		void removeCard(int);
		~Hand();
};



class Player{
	private:
		Hand hand;
		int* books;
		int nBooks;
	public:
		Player();
		Hand getHand();
		int* getBooks();
		int getnBooks();
		int addCard(Card,int);
		int randomCard();
		void makeHand(Deck*);
		void setHand(Hand);
		void printHand();
		void setBook(int);
		void newHand(Hand*);
		void copyHand(Hand*);
		void addHand(Card*,int);
		void removeBook(int);
		~Player();	
};

class Game{
	private:
		Deck* decks;
		Player players[2];
		bool endGame;
	public:
		Game();
		bool playerTurn(int);
		bool computerTurn(int);
		bool playerBase();
		bool computerBase();
		int isGood(int);
		int handSearch(int,int);
		int goFish(int);
		void printHand(int);
		void startGame();
		void playerStatus(int);
		void computerStatus(int);
		void takeCards(int,int,int);
		void playerBooks(int);
		void playerRules();
//		void pause(int);
		~Game();
};

#endif
