#include "player.h"
#include "deck.h"
#include <iostream>
using namespace std;

player() {
	
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

void player::swap(int r, int c, card theCard, deck theDeck)
{
	// set card to toDiscard, place passed card into hand
	card toDiscard = hand[r][c];
	hand[r][c] = theCard;

	// make sure card is flipped rightside-up
	cardvisible[r][c] = true;

	// discard toDiscard
	theDeck.setDiscard(toDiscard);
}

bool player::flip(int r, int c)
{
	// check if the card is face down
	if (cardvisible[r][c] == false)
	{
		// flip it and return true
		cardvisible[r][c] == true;
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
		if (!(cardvisible[0][i] && cardvisible[1][i]))
		{
			isAllFaceUp = false;
		}
	}
}
