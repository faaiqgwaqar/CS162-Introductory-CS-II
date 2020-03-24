/***************************************************
 * Filename: Card.hpp
 * Author: Faaiq Waqar
 * Date: 02/04/2019
 * Description: Header file that contains the declaration
 * for 
 * Input: n/a
 * Output: Card class declared
****************************************************/

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
