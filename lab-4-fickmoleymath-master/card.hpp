#ifndef WAQARF_CARD_HPP
#define WAQARF_CARD_HPP

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

#endif
