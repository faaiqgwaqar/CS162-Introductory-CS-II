/************************************************
 * Filename: game.cpp
 * Author: faaiq waqar
 * Date: 02/04/2019
 * Description: contains declaration of game class
 * Input: libraries
 * Output: declared usable game class
***********************************************/

#ifndef WAQARF_GAME_HPP
#define WAQARF_GAME_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class Game{
        private:
                Deck* decks;
                Player players[2];
                bool endGame;
        public:
                Game();
                bool playerTurn(int);
                bool computerTurn(int);
                bool playerBase();
                bool computerBase();
                int isGood(int);
                int handSearch(int,int);
                int goFish(int);
                void printHand(int);
                void startGame();
                void playerStatus(int);
                void computerStatus(int);
                void takeCards(int,int,int);
                void playerBooks(int);
                void playerRules();
		~Game();
};
                
#endif
