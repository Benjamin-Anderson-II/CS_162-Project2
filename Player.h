#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player { // this is essentially a wrapper for the Hand
private:
	Hand* hand;		//player hand
	bool isUser;	//true if is user
public:
	Player(bool b); 	//Constructor
	Hand* getHand();	//gets the hand
	~Player();			//Destructor
};

#endif