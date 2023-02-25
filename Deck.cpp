#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"

using namespace std;

Deck::Deck(){
	int count = 0;
	for (int i = 0; i < 4; i++){ // suit
		for (int j = 1; j <= 13; j++){ // rank
			cards[count] = new Card(j, i);
			count++;
		}
	}
}

void Deck::shuffle(){ // loops through and flips iterated index with random index
	int toSwap;
	Card* temp;
	srand(time(NULL));
	for(int i = 0; i < 52; i++){
		toSwap = rand() % 52;
		temp = cards[i];
		cards[i] = cards[toSwap];
		cards[toSwap] = temp;
	}
}

Card* Deck::getTopCard(){ // 0th index
	return cards[52-numCards];
}

Card* Deck::getCardAtIndex(int idx){
	return cards[idx];
}

int Deck::size(){
	return numCards;
}

Card* Deck::pop(){
	int tmpIdx = 52-numCards;
	numCards--;
	return cards[tmpIdx];
}

Deck::~Deck(){
	for(int i = 0; i < 52; i++){
		delete cards[i];
	}
}