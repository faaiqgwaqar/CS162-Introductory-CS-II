/********************************************
 * Filename:gofish.pp
 * Author:faaiq waqar
 * Date:02/04/2019
 * Description:contains main function for go fish
 * Input: header files
 * Output: game running
 *******************************************/

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

int main(){
	Game game;
	
	cout << "Initiallizing Game ... \n";
	cout << "Full Deck ... Cards: 52\n";
	cout << "Shuffling ... \n";
	cout << " ... \n";
	cout << "Begin! \n\n\n";
	
	game.startGame();
	
	return 0;
}
