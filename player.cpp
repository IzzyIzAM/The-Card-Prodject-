#include "player.h"
#include "deck.h"
#include <iostream>
using namespace std;

player::player()
{
	
}

void player::setHand(card arry[6]) {
//sets all of the cards to the apropriate cards
int index = 0;
for (int i = 0; i < 2; i++)
	for (int j = 0; j < 3; j++) {
		hand[i][j].setCard(arry[index].cardType());
		cardvisable[i][j] = false;
		index++;
	}
}

void player::placeCard(card theCard, int r, int c) {
	hand[r][c] = theCard;
	cardvisable[r][c] = true;
}

card player::getCard(int r, int c) {
	//returns the card if its facing up
	card ret(15);
	if (cardvisable[r][c])
	{
		return hand[r][c];
	}
	return ret;
}
	 
void player::print() {
	//prints the players hand
	card ret(15);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cardvisable[i][j])
				hand[i][j].print();
			else
				ret.print();
		}
		cout << endl;
	}
}

void player::swap(int r, int c, card theCard)
{
	deckOfCards theDeck;
	// set card to toDiscard, place passed card into hand
	card toDiscard = hand[r][c];
	hand[r][c] = theCard;

	// make sure card is flipped rightside-up
	cardvisable[r][c] = true;

	// discard toDiscard
	theDeck.setDiscard(toDiscard);
}

bool player::flip(int r, int c)
{
	// check if the card is face down
	if (cardvisable[r][c] == false)
	{
		// flip it and return true
		cardvisable[r][c] == true;
		return true;
	}
	else
	{
		// return false, didn't flip
		return false;
	}
}

bool player::isAllFaceUp()
{
	// check for any unflipped cards
	bool isAllFaceUp = true;
	for (int i = 0; i < 2; i++)
	{
		if (!(cardvisable[0][i] && cardvisable[1][i]))
		{
			isAllFaceUp = false;
		}
	}
}

int player::score()
{
	// check all the rules!
	// some variables for DA RULES!
	int totalScore = 0;

	for (int i = 0; i < 3; i++)
	{
		// count card values if they're not a pair
		if (hand[0][i].valueofcard() != hand[1][i].valueofcard())
		{
			totalScore += hand[0][i].valueofcard();
			totalScore += hand[1][i].valueofcard();
		}
	}

	return totalScore;
}