/************************************************
 * Filename: Hand.hpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: contains the declaration of the 
 * hand class
 * Input: libraries
 * Output: hand class decleration
************************************************/

#ifndef WAQARF_HAND_HPP
#define WAQARF_HAND_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

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

#endif
