#include "Player.h"

using namespace std;

Player::Player(bool b){
	isUser = b;
	hand = new Hand();
}

Hand* Player::getHand(){
	return hand;
}

Player::~Player(){
	delete hand;
}