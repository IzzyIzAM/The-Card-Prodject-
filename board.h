#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "deck.h"
using namespace std;

class Board
{
public:
    player *players;
    Board(int);
    card draw();
    void pass(bool);
    void deal();
    card takeFromDeck(bool);
    card takeFromDiscard(bool);
    int getNumPlayers(); 
	deckOfCards *TheDeck;
private: 
    int *scoreboard;
    int numOfPlayers;
};

#endif
