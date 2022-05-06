#include <iostream>
#include "deck.h"
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
  board theBoard;
  player playerOne; // Creates Player 1
  player playerTwo;
  deck decks;
  int currentTurn;
  int playerAmount;
  
  cout << "Game Start";

  deckOfCards theDeck; // Creates the Deck  
  
  theBoard.deal(); // Deals cards to both players
  
  cout << "Setting up deck";
  cout << "Shuffling deck";
  cout << "Dealing hands";
  return 0; 
}
