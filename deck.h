
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class card
{
public:
	card() { currentCard = 0; }

	card(int val) {
		currentCard = val;
	}

	void setCard(card val) { currentCard = val.cardType(); }

	void setCard(int val) { currentCard = val; }

	int valueofcard() { return value[currentCard]; }

	string visual() { return vis[currentCard]; }

	int cardType() { return currentCard; }

	void print() { cout << "[" << vis[currentCard] << "]"; }
private:
	string vis[16] = { "-3","A","2","3","4","5","6","7","8","9","10","J","Q","K","JK"," " };
	int value[16] = { 100,1,2,3,4,5,6,7,8,9,10,10,0,-2,0 };
	int currentCard;

};


// Class for deck of cards
class deckOfCards {
private:
	card* deck;
	int numdeck, totalcards, index; //store the number of decks 2 for every 2 players, stors total number of cards, stores the index of the card
	card discard; // discarded card

	void reset();

public:
	deckOfCards(int num);

	void randomize();

	card draw();

	void setDiscard(card car) { discard.setCard(car); };

	card getDiscard() { return discard;	};

};

#endif
