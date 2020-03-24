/************************************************
 * Filename: Player.hpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: declaration for player class
 * Input: libraries
 * Output: plaer class declaration
************************************************/

#ifndef WAQARF_PLAYER_HPP
#define WAQARF_PLAYER_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

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

#endif
