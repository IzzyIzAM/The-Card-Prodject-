#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "deck.h"

using namespace std;

void deckOfCards::reset() {
	index = 0;
	for (int k = 1; k <= numdeck; k++) { //for the number of decks
		for (int j = 1; j <= 4; j++) { // for each suit
			for (int i = 1; i <= 13; i++) { // for each card
				deck[index].setCard(i);
				index++;
			}
		}
	}

	for (int k = 1; k <= numdeck; k++) { //for the number of decks
		for (int j = 1; j <= 2; j++) {
			deck[index].setCard(14);
			index++;
		}
	}

	index = 0;
}

deckOfCards::deckOfCards()
{
	int currentCard = NULL;
}

deckOfCards::deckOfCards(int num) {

	numdeck = num / 2;
	totalcards = 52 * numdeck;
	deck = new card[totalcards];
	index = 0;
		//set all cards to default
	for (int t = 0; t < totalcards; t++) {
		deck[t].setCard(0);
	}

	//maksure we have enough and the proper cads
	reset();
	randomize();

}

void deckOfCards::randomize() {
	for (int i = 0; i < totalcards; i++) {
			
		//gets random place to swap with
		int j = rand() % totalcards;
				
		//swap places 
		int temp = deck[i].cardType();
		deck[i].setCard(deck[j].cardType());
		deck[j].setCard(temp);
	}
	index = 0;
}
