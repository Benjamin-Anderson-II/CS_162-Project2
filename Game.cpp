#include "Game.h"

using namespace std;
#include <cstring>
#include <string>

Game::Game(){
	cards = new Deck();
	cards->shuffle();
	players[0] = new Player(0);//user
	players[1] = new Player(1);//CPU
}

Deck* Game::getDeck(){
	return cards;
}

Player* Game::getPlayer(int p){
	return players[p];
}

void Game::start(){
	for(int i = 0; i < 2; i++){ // loop between players
		for(int j = 0; j < 8; j++){ // loop to add cards to the hand
			players[i]->getHand()->addCard(cards->pop());
		}
	}
	cardOnField = cards->pop(); // remove card from top of deck and make it the cardOnField
}

void Game::showTopCard(){
	cout << "Deck Size: " << cards->size() << endl;
	cout << "Top Card: \n\t{";
	cardOnField->display();
	cout << "}\n";
}

bool Game::userTurn(){
	//print stuff
	showTopCard();
	cout << "Player's Hand: (0-" << (players[0]->getHand()->size()-1) << ")\n\t";
	Hand* currHand = players[0]->getHand();
	players[0]->getHand()->show();


	string input;
	while(true){
		cin >> input;
		if(input[0]=='d'||isValidInput(input, currHand->size())){
			int idx = atoi(input.c_str());

			//if the user inputs a string starting with 'd' then draw
			if(input[0]=='d'){
				if(draw(0)) 
					return true;
				else
					idx = currHand->size()-1;
			}

			//compares the card on the field with the selected card
			if(compareCards(cardOnField, currHand->getCard(idx))){
				if(currHand->getCard(idx)->getRank()==8){
					while(true){
						cout << "Select a suit 0-3(D, H, S, C)\n\t";
						cin >> input;
						if(isValidInput(input, 4)){
							currHand->getCard(idx)->setSuit(atoi(input.c_str()));
							break;
						} else {
							cerr << "Invalid Input\n";
						}
					}
				}
				cardOnField = currHand->pop(idx); //removes the card from the hand and puts it on the field
				if(currHand->size()==0) return true; // if the hand size is 0, then you win
			}
			break;
		} else {
			cerr << "Invalid Input\n\t";
		}
	}
	return false;
}

bool Game::compTurn(){

	//print stuff
	Hand* currHand = players[1]->getHand();
	cout << "Computer Hand Size: " << players[1]->getHand()->size() << endl;

	Card* tmp;
	for(int i = 0; i < currHand->size(); i++){ // loop through all cards and play the first one that is viable
		tmp = currHand->getCard(i);
		if(compareCards(cardOnField, tmp)){ //-------- is card viable?
			if(tmp->getRank() == 8){ //--------------- is card wild (8)
				tmp->setSuit(getModeSuit(currHand));// set the suit to the most frequent suit in hand
				i = currHand->size()-1;
			}
			cardOnField = currHand->pop(i); //removes the card from the hand and puts it on the field
			if(currHand->size()==0) return true; // if the band size is 0, then end the game
			break;
		}
	}
	if(draw(1)) return true; // if the deck size is 0, then end the game
	return false;
}

int Game::getModeSuit(Hand* currHand){
	int suit = currHand->getCard(0)->getSuit();
	int mode = suit;
	int count = 1;
	int countMode = 1;

	for(int j = 1; j < currHand->size(); j++){
		if(currHand->getCard(j)->getSuit() == suit){
			count++;
		} else {
			if (count > countMode){
				countMode = count;
				mode = suit;
			}
			count = 1;
			suit = currHand->getCard(j)->getSuit();
		}
	}
	return mode;
}

bool Game::draw(int player){ //returns true if end of deck reached
	Hand* currHand = players[player]->getHand();
	while(cards->size()!=0){
		currHand->addCard(cards->pop());
		if(compareCards(currHand->getCard(currHand->size()-1), cardOnField)) return false;
	}
	return true;
}

bool Game::compareCards(Card* c1/*deck*/, Card* c2/*hand*/){
	if(c2->getRank()==8)return true;
	if(c1->getRank()==c2->getRank())return true;
	if(c1->getSuit()==c2->getSuit())return true;
	return false;
}

bool Game::isValidInput(string input, int handSize){
	try{
		if(input[0]-'0'>9) throw 0;
		int inp = atoi(input.c_str());
		if(inp>=handSize) throw 0;
	} catch(...) {
		return false;
	}
	return true;
}

void Game::end(){
	if(players[0]->getHand()->size()==0) // user wins if hand size is 0
		cout << "User Wins!\n";
	if(players[1]->getHand()->size()==0) // computer wins if hand size is 0
		cout << "Computer Wins!\n";
	if(cards->size()==0){ // in case of deck emptied
		if			(players[0]->getHand()->size() < players[1]->getHand()->size()){ // when the user has less cards than the computer
			cout << "User Wins!\n";
		} else if	(players[0]->getHand()->size() > players[1]->getHand()->size()){ // when the computer has less cards than the user
			cout << "Computer Wins!\n";
		} else {
			cout << "Tie!\n"; //same number of cards in each hand
		}
	}
}

Game::~Game(){
	delete cards;
	delete players[0];
	delete players[1];
}