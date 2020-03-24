#ifndef WAQARF_HAND_HPP
#define WAQARF_HAND_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

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

#endif
