#include "deck.hpp"

using namespace std;

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

