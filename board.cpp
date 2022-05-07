#include <iostream>
#include "deck.cpp"
using namespace std;

class board {
private:
	deckOfCards TheDeck;
	int* scoreboard;
	int numOfPlayers;

public:
	player* players;

	board(int numOfPlayers) {
		players = new player[numOfPlayers];
		this->numOfPlayers = numOfPlayers;
		scoreboard = new int[numOfPlayers];
	
	}
	
	void score() {
	//counts the players scores and displays the score at the end
	
	};
	
	card draw() {
	//draws the table
		return TheDeck.draw();
	};

	void pass() {
	//draws : Takes a card from the top of the deck and 
	//puts it in discard stash
	};

	void deal() {
		card array[6];
		for (int i = 0; i < numOfPlayers; i++)
			for (int j = 0; j < 6; j++) {
				arry[j].setCard(draw());
				players[i].setHand(arry);

			}
	}

/*
	card takeFromDeck() {
		
	}
	card takeFromDiscard() {
	
	}
*/
	int getNumPlayers() { return numOfPlayers; };

};
