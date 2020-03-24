/**************************************************
 * Filename:deck.hpp
 * Author:faaiq waqar
 * Date:02/04/2019
 * Description:containts declaration for deck calss
 * Input: libraries
 * Output:declaration of deck class
**************************************************/

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
                int getnCards();
                ~Deck();
};

#endif

