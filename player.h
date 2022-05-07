#pragma once
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

class player {
    private:
	card hand[2][3];
	bool cardvisable[2][3];
	bool isPlayer;
public:
	//initializes a empty player
	player();
    void setHand(card arry[6]);
    void placeCard(card theCard, int r, int c);
    card getCard(int r, int c);
    void print();
    void swap(int r, int c, card theCard, deck theDeck); // swap drawn card with existing one
    bool flip(int r, int c); // flip chosen card, return if true if flipped
    bool isAllFaceUp(); // determines if play should end
}

#endif
