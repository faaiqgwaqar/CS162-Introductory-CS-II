#ifndef WAQARF_DECK_HPP
#define WAQARF_DECK_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

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

#endif
