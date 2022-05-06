#include <iostream>
#include "deck.h"
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
  board theBoard;
  player thePlayer;
  deck decks;
  int currentTurn;
  int playerAmount;
  
  cout << "Game Start";

  deckOfCards theDeck; // Creates the Deck
  
  cout << "Please enter number of players(2-4): ";
  cin >> playerAmount;
 
  while(true)
  {
      if(playerAmount < 2 || playerAmount > 4)
      {
      cout << "Please enter valid number of players(2-4): ";
      cin >> playerAmount;
      }
      else
        break;
  }
  
  theBoard.deal();// Deals cards to both players
  
  cout << "Settiny up deck";
  cout << "Shuffling deck";
  cout << "Dealing hands";
  return 0; 
}
