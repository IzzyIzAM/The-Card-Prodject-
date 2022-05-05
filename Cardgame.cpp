// Cardgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ASDFGHUODHGOIADGHASOIGHASOIG

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class card
{
public:
	card() {
		currentCard = 0;
	}
	
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
	string vis[16] = { "-3","A","2","3","4","5","6","7","8","9","10","J","Q","K","JK"," "};
	int value[16] = { 100,1,2,3,4,5,6,7,8,9,10,10,0,-2,0};
	int currentCard;
	
};

class deckOfCards {
private:
	card* deck;
	int numdeck,totalcards,index; //store the number of decks 2 for every 2 players, stors total number of cards, stores the index of the card
	card discard; // discarded card

	void reset() {
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

public:
	deckOfCards(int num = 1) {

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

	void randomize() {
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

	card draw() {
		int i = index;
		index++;
		return deck[i];
	}

	void setDiscard(card car) {
		discard.setCard(car);
	}

	card getDiscard() {
		return discard;
	}
	
};

class player {
private:
	card hand[2][3];
	bool cardvisable[2][3];
	bool isPlayer;
public:
	//initializes a empty player
	player() {
		
	}

	void setHand(card arry[6]) {
		//sets all of the cards to the apropriate cards
		int index = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++) {
				hand[i][j].setCard(arry[index].cardType());
				cardvisable[i][j] = false;
				index++;
			}
	}

	void placeCard(card theCard, int r, int c) {
		hand[r][c] = theCard;
		cardvisable[r][c] = true;
	}

	card getCard(int r, int c) {
		//returns the card if its facing up
		card ret(15);
		if (cardvisable[r][c])
		{
			return hand[r][c];
		}
		return ret;
	}
	 
	void print() {
		//prints the players hand
		card ret(15);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (cardvisable[i][j])
					hand[i][j].print();
				else
					ret.print();
			}
			cout << endl;
		}
	}

};

class board {
private:
	deckOfCards TheDeck;
	player* players;
	int* scoreboard;
	int numOfPlayers;

public:

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
		card arry[6];
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

};





int main()
{
	player person; // Creates a person object
	cout << "** Current Players **" << endl;

	return 0;
}
