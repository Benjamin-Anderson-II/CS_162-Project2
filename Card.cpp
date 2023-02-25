#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(int r, int s){
	rank = r;
	suit = s;
}

int Card::getRank(){
	return rank;
}

int Card::getSuit(){
	return suit;
}

void Card::setSuit(int s){
	suit = s;
}

void Card::display(){
	switch(rank){
		case 1:
		cout << "A";
		break;
		case 11:
		cout << "J"; 
		break;
		case 12:
		cout << "Q";
		break;
		case 13:
		cout << "K";
		break;
		default:
		cout << rank;
		break;
	}
	cout << ":";
	switch(suit){
		case 0:
		cout << "D";
		break;
		case 1:
		cout << "H";
		break;
		case 2:
		cout << "S";
		break;
		case 3:
		cout << "C";
		break;
		default: 
		break;
	}
}