#include "card.hpp"

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

