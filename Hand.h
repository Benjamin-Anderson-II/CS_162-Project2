#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {
private:
	Card* arr[52]; 		// since I'm dynamically allocating memory I just set it to be the max possible size
	int numCards = 0;	// Number of cards in the hand.
public:
	void addCard(Card* c);		//adds a card to the hand, and increments numCards
	Card* getCard(int index);	//gets a card at a given location
	int size();					//returns numCards
	Card* pop(int index);		//takes a card from an index out of the hand, shifts the items down, and decreases numCards
	void show();				//shows the player hand in {r:s, r:s, ..., r:s} format
};

#endif