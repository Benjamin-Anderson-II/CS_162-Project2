/*
	This file describes the Card class.
*/
#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
	private:
		Card* cards[52];
		int numCards = 52;  // Number of cards remaining in the deck.
	public:
		Deck();						//Basic Constructor

		Card* getTopCard();			// gets the card at (52-numCards)
		Card* getCardAtIndex(int);	// gets the card at a specified index
		void shuffle();				// shuffles the deck
		int size();					// returns numCards
		Card* pop();				// returns the "top card" and decreases the number of cards

		~Deck();					// Destructor for all items in Deck
};
#endif
