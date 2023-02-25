#include "Hand.h"

using namespace std;

void Hand::addCard(Card* c){
	arr[numCards] = c;
	numCards++;
}

Card* Hand::getCard(int index){
	return arr[index];
}

Card* Hand::pop(int index){
	Card* tmp = arr[index];
	for(int i = index; i < numCards-1; i++){
		arr[i] = arr[i+1];
	}
	numCards--;
	return tmp;
}

int Hand::size(){
	return numCards;
}

void Hand::show(){
	cout << "{";
	for(int i = 0; i < numCards; i++){
		arr[i]->display();
		cout << ", ";
	}
	cout << "\b\b}\n";
}