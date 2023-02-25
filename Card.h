/*
	This file describes the Card class.
*/
#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
	private:
		int rank;// (0-12) -> (ace->king)
		int suit;// (0-3)  -> (d,h,s,c)
	public:
		Card(int r, int s);		//Constructor: r=rank, s=suit
		int getRank();			//gets the rank of the given card
		int getSuit();			//gets the suit of the given card
		void setSuit(int s);	//sets the suit of the given card. used for 8s
		void display();			//displays the card in {r:s} format
};
#endif
