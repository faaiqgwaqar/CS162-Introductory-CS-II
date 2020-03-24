#include "gamerule.hpp"

using namespace std;

Card::Card(){
	rank = 0;
	suit = 0;
}

void Card::setCard(int newRank,int newSuit){
	rank = newRank;
	suit = newSuit;
}

int Card::getRank(){
	return rank;
}

int Card::getSuit(){
	return suit;
}

Card::~Card(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////

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

int Deck::getnCards(){
	return nCards-indexCards;
}

Deck::~Deck(){ //basic c++ gen destructor

}

//////////////////////////////////////////////////////////////////////////////////////////////////

Hand::Hand(){
	nCards = 0; //basic constuctor
}

Hand::Hand(const Hand& newHand){ //constructs on both accounts, passes in a hand
	this-> nCards = newHand.nCards;
	this-> cards = new Card[this->nCards];
	for (int i = 0; i < this-> nCards;i++) //populates for number of cards
		this->cards[i] = newHand.cards[i];
}

void Hand::operator = (const Hand& newHand){
	this-> nCards = newHand.nCards;
        this-> cards = new Card[this->nCards];
        for (int i = 0; i < this-> nCards;i++) //populates for number of cards
                this->cards[i] = newHand.cards[i];
}

Card* Hand::getHand(){
	return cards;
}

Card* Hand::addCard(){
	Card* temp;
	temp = new Card[nCards + 1];
	for(int i = 0; i < nCards; i++)
		temp[i] = cards[i];
	if (nCards > 0){
		delete[] cards;
	}
	return temp;
}

void Hand::setCard(Card newDeal){
	cards = addCard();
	cards[nCards] = newDeal;
	nCards++;
}

int Hand::getnCards(){
	return nCards;
}

void Hand::removeCard(int exCard){
	nCards--;
	Card* temp = new Card[nCards];
	int j = 0;
	for(int i = 0; i < nCards+1;i++){
		if(i != exCard){
			temp[j] = this->cards[i];
			j++;
		}
	}
	delete[] cards;
	cards = temp;
}

Hand::~Hand(){
	if(nCards > 0);
		delete[] cards; //bye bye mem leaks
}

//////////////////////////////////////////////////////////////////////////////////////////////////

Player::Player(){
	books = new int[1];
	nBooks = 0;
}

Hand Player::getHand(){
	return hand;
}

int* Player::getBooks(){
	return books;
}

int Player::getnBooks(){
	return nBooks;
}

int Player::addCard(Card newCard,int num){
	hand.setCard(newCard);
	if(num == 0)
		cout << "Obtained: " << newCard.getRank() << " ...\n";
	return newCard.getRank();
}

int Player::randomCard(){
	srand(time(NULL));
	int rCard = rand() % hand.getnCards();
	return hand.getHand()[rCard].getRank();
}

void Player::makeHand(Deck* newDeck){
	for(int i = 0;i < 7;i++)
		hand.setCard(newDeck->dealCard());
}

void Player::setHand(Hand newHand){
	hand = newHand;
}

void Player::printHand(){
	cout << "Cards in Hand: \n";
	for(int i = 0; i < hand.getnCards();i++){
	int indRank = hand.getHand()[i].getRank();
	int indSuit = hand.getHand()[i].getSuit();
	cout << indRank << "::";

	if(indSuit == 0)
		cout << "C \n";
	else if(indSuit == 1)
		cout << "D  \n";
	else if(indSuit == 2)
		cout << "H  \n";
	else if(indSuit == 3)
		cout << "S  \n";
	}
	cout << "\n\n";
}

void Player::setBook(int newBook){
	int* temp = new int[nBooks+1];
	for (int i = 0; i < nBooks; i++){
		temp[i] = books[i];
	}
	temp[nBooks] = newBook;
	nBooks++;
	delete[] books;
	books = temp;
	removeBook(newBook);
}

void Player::newHand(Hand* newHand){
	*newHand = hand;
}

void Player::copyHand(Hand* newHand){
	hand.~Hand();
	hand = *newHand;
}

void Player::addHand(Card* sCard,int nCards){
	for(int i = 0; i < nCards;i++)
		hand.setCard(sCard[i]);
}

void Player::removeBook(int newBook){
	for(int i = 0; i < hand.getnCards(); i++){
		if(hand.getHand()[i].getRank() == newBook)
			hand.removeCard(i);
	}
}

Player::~Player(){
	delete[] books;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Game::Game(){
	endGame = false;
	decks = new Deck;
	decks -> shuffleCard();
	players[0].makeHand(decks);
	players[1].makeHand(decks);
}


bool Game::playerTurn(int i){
	cout << "Player Turn ... \n";
	if(players[i].getHand().getnCards() == 0){
		cout << "Empty Hand ... Go Fish ... \n";
		goFish(i);
	}

	this->playerStatus(i);
	cout << "Search For What Card? ... \n";
	int search = isGood(i);
	cout << "\nSearched For ... " << search << "\n";
	cout << "Opponent Had ... " << handSearch(!i,search) << "\n\n";
	if (handSearch(!i,search) == 0) {
		cout << "Go Fish ...\n\n";
		int fish = goFish(i);
		if (fish == search)
			return true;	
	}

	else{
		takeCards(i,search,handSearch(!i,search));
		return true;
	}
	
	return false;
}

bool Game::computerTurn(int i){
	cout << "Computer Turn ... \n";
	int search = players[i].randomCard();
	cout << "\nComputer Seached For ... " << search << "\n";
	cout << "Player has ... " << handSearch(!i,search) << "\n";
	if(handSearch(!i,search == 0)){
		int fish = goFish(i);
		if(fish == search){
			cout << "Computer Drew ..." << search << "\n";
			return true;
		}
	}
	else{
		takeCards(i,search,handSearch(!i,search));
		return true;
	}

	return false;
}

bool Game::playerBase(){
	bool turn = true;
	while (turn) {
		turn = this -> playerTurn(0);
		this -> playerBooks(0);
		this -> playerStatus(0);
		if(players[0].getnBooks()+players[1].getnBooks() == 13)
			return true;
	}
	return false;
}

bool Game::computerBase(){
	bool turn = true;
	while(turn){
		turn = this -> computerTurn(1);
		this -> playerBooks(1);
		cout << "Computer Books ... " << players[1].getnBooks() << ". \n";
		if(players[0].getnBooks()+players[1].getnBooks() == 13);
			return true;
	}
	return false;
}

int Game::isGood(int i){
	bool bad = true;
	string temp;
	while(bad){
		cin >> temp;
		if(handSearch(i,atoi(temp.c_str())) == 0)
			cout << "Invalid ... Try Again\n";
		else
			bad = false;
	}
	return atoi(temp.c_str());
		
}

int Game::handSearch(int i,int search){
	int searchI = 0;
	Hand* temp = new Hand;
	this -> players[i].newHand(temp);
	for(int j = 0 ; j < temp -> getnCards();j++){
		if(search == temp->getHand()[j].getRank()){
			searchI++;
		}
	}

	delete temp;
	return searchI;
}

int Game::goFish(int i){
	int fish = players[i].addCard(decks->dealCard(),i);
	return fish;
}

void Game::printHand(int i){
	players[i].printHand();
}

void Game::startGame(){
	cout << "Welcome To Go Fish ... \n";
	playerRules();
	while(!endGame){
		playerBase();
		cout << "Cards Left In Deck ... " << decks->getnCards() << "\n";
		cout << "\n\n............................................................\n\n";
		computerBase();
		cout << "\n\n............................................................\n\n";
	}

	if(players[0].getnBooks() > players[1].getnBooks())
		cout << "Player Won With This Many Books ... " << players[0].getnBooks() << "\n";
	else
		cout << "Computer Won With This Many Books ... " << players[1].getnBooks() << "\n";
}

void Game::playerStatus(int i){
	cout << "Player Hand Is ... \n";
	this -> printHand(i);
	cout << "Player Has ... " << players[i].getnBooks() << " Books ... \n";
	if(players[i].getnBooks() > 0){
		cout << "Player Books Are ...";
		for (int j = 0; j < players[i].getnBooks();j++){
			cout << players[i].getBooks()[j] << " ";
		}
	cout << "\n\n";
	}
}

void Game::computerStatus(int i){

}

void Game::takeCards(int i,int search,int nCards){
	Hand* temp = new Hand;
	players[!i].newHand(temp);
	Card* take = new Card[nCards];
	int j = 0;
	for(int k = 0; k < temp->getnCards();k++){
		if(search == temp->getHand()[k].getRank()){
			take[j] = temp->getHand()[k];
			j++;
			temp->removeCard(k);
			k--;
		}
	}
	players[!i].copyHand(temp);
	players[i].addHand(take,nCards);
	delete[] take;
	delete temp;
}

void Game::playerBooks(int i){
	for(int j = 0;j < 13;j++){
		if(handSearch(i,j) == 4){
			players[i].setBook(j);
			if (i == 0)
				cout << "Player Created Book of ... " << j << "\n\n";
			else
				cout << "Computer Created Book of ... " << j << "\n\n";
		}

	}
}

void Game::playerRules(){
	cout << "------------- Rules Of Go Fish ------------\n\n";
	cout << "The deck of cards is shuffled, randomizing the order of the cards.\n";
	cout << "Each player is dealt a hand of 7 cards. Only the player is able to see the cards in their hand.\n";
	cout << "The remaining cards are placed face-down (i.e. with their rank";
	cout << " and suit hidden) on the table to form the 'stock'\n";
	cout << "One of the players (player A) begins the game by asking the other player (player B) ";
	cout << "for all of his/her cards of a specific rank \n";
	cout << "(e.g. 'Please give me all of your 7's'). To ask for a given rank,";
	cout << " a player must have at least one card of that rank in his/her \nhand.";
	cout << "If player B has cards of the requested rank, he/she must ";
	cout << "give all of his/her cards of that rank to player A, and player A \ngets to take another turn.";
	cout << "If player B does not have any cards of the requested \nrank, he/she says 'go fish',";
	cout << "and player A must select one card from the stock. If that card has the rank player";
	cout << " A originally requested, \nthen player A gets to take another turn.\n";
	cout << "Otherwise, it becomes player B's turn.\n";
	cout << "If at any point a player runs out of cards, then, when it is that player's";
	cout << " turn to play, they may draw a card from the stock \nand ask for cards of that ";
	cout << "rank. If a player runs out of other cards when it is the other player's turn to";
	cout << " ask for a rank, \nthe other player may continue to ask for a rank and draw from";
	cout << " the stock until they draw a rank other than the one they asked\n for.\n";
	cout << "If a player collects all four cards of the same rank, this is called a";
	cout << " 'book', and the player lays down his/her book on the \ntable. Both players";
	cout << " may see the cards in every book that's laid down.\n";
	cout << "The game continues with the players alternating turns until all";
	cout << " of the books are laid down. At the end of the game, the player";
	cout << " \nwho laid down the most books wins.\n\n";
}

//void Game::pause(int i){
//	string prompt[2] = {"Computer, Player"};
//	cout << "Press Enter for " << prompt[i] << "Turn ... \n";
//	cin.ignore(!i);
//	char pause = cin.get();
//	system("clear");
//}

Game::~Game(){
	delete decks;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
