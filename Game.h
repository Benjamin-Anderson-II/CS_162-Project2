 #ifndef GAME_H
#define GAME_H


#include "Deck.h"
#include "Player.h"
#include <iostream>

class Game {
private:
	Deck* cards;		//The deck of Cards
	Player* players[2];	//The array consisting of te two players
	Card* cardOnField;	//Pointer to the Card on the field

	void showTopCard();									//shows the cardOnField
	bool isValidInput(std::string input, int numCards);	//tests to see weather the input from the user is valid
	bool compareCards(Card*, Card*);					//compares two cards, returns true if the card is playable
	bool draw(int player); 								//0=user, 1=computer
	int getModeSuit(Hand*);								//gets the mode of the hand in terms of suit
public:
	Game();					//Constructor

	Deck* getDeck();		//returns the deck
	Player* getPlayer(int);	//returns a specific player
	void start();			//starts the game
	bool userTurn();  		// returns true if user wins
	bool compTurn();  		// returns true if computer wins
	void end();				//ends the game

	~Game(); 				//destructor for the Game Object
};
#endif