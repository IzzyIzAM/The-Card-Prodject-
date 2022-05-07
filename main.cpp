#include <iostream>
#include <random>
#include "deck.h"
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
  board theBoard;
  player thePlayer; // Creates Player 1
  deckOfCards decks;
  card theCard;
  int currentTurn = 1;
  bool gameOn = true;
  int playerAmount;
  int row;
  int column;
  int randRow;
  int randCol
  bool isPlayer = true;
  
  cout << "**Setting Board and Hands**" << endl;
  cout << endl;

  deckOfCards theDeck; // Creates the Deck  
  
  theBoard.deal(); // Deals cards to both players
  
  
  cout << "Please enter the card you would like to flip in row 1(1-3): ";
  cin >> column;
  thePlayer.flip(1, column); // Flips players first chosen card
  
  cout << "Please enter the card you would like to flip in row 2(1-3): ";
  cin >> column; 
  thePlayer.flip(2, column); // Flips players second chosen card
  
  thePlayer.flip(1, rand() % 3 + 1); // Flips bots first card
  thePlayer.flip(2, rand() % 3 + 1); // Flips bots second card
  
  decks.setDiscard(deck.draw()); // Sets top of discard pile
  
  cout << endl;
  cout << "**Starting game**" << endl;
  cout << endl;
  
 while(gameOn) // Starts the game
 {
	 
	 if(currentTurn = 1)
	 {
		 
		 cout << "**Player turn**" << endl;
		 
		 theCard = decks.getDiscard();
		 cout << "Top of Discard Pile: ";
		 theCard.print(); // Prints the top of discard pile
		 
		 cout << endl; 
		 player.print();
		 
		 
		 
		 
	 }
	 
 }
 

  return 0; 
}
