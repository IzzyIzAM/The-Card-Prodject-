#include <iostream>
#include "deck.h"
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
  board theBoard;
  player thePlayer; // Creates Player 1
  deck decks;
  int currentTurn;
  int playerAmount;
  int row;
  int column;
  
  cout << "Game Start";

  deckOfCards theDeck; // Creates the Deck  
  
  theBoard.deal(); // Deals cards to both players
  
  
  cout << "Please enter the card you would like to flip in row 1(1-3): ";
  cin >> column;
  thePlayer.flip(1, column);
 
  
  cout << "Setting up deck";
  cout << "Shuffling deck";
  cout << "Dealing hands";
  return 0; 
}
