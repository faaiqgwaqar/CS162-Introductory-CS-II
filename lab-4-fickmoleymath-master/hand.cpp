#include "hand.hpp"

using namespace std;

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

