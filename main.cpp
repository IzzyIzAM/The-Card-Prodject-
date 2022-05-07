#include <iostream>
#include <random>
#include "deck.h"
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
	Board theBoard(2); //Creates 2 players in the board
  	deckOfCards decks(2);
  	card theCard;
	
  	int currentTurn = 0;
  	bool gameOn = true;
	
  	int row;
  	int column;
	
  	int randRow;
  	int randCol;
		
  	bool isPlayer = true;
	
	int playerChoice;
	int botChoice;
	
	int playerScore;
	int botScore;

  
  	cout << "**Setting Board and Hands**" << endl;
  	cout << endl; 
  
  	theBoard.deal(); // Deals cards to both players
  
  
  	cout << "Please enter the card you would like to flip in row 1(1-3): ";
  	cin >> column;
  	theBoard.players[0].flip(1, column); // Flips players first chosen card
  
  	cout << "Please enter the card you would like to flip in row 2(1-3): ";
  	cin >> column; 
  	theBoard.players[0].flip(2, column); // Flips players second chosen card
  
  	theBoard.players[0].flip(1, rand() % 3 + 1); // Flips bots first card
  	theBoard.players[0].flip(2, rand() % 3 + 1); // Flips bots second card
  
  	decks.setDiscard(decks.draw()); // Sets top of discard pile
  
  	cout << endl;
  	cout << "**Starting game**" << endl;
  	cout << endl;
  
 	while(gameOn) // Starts the game
 	{
		int whoseTurn = currentTurn % theBoard.getNumPlayers();
		
		if(whoseTurn == 0) // Player turn
		{
			isPlayer = true;
			cout << "**Player turn**" << endl;
		 
     			// display available card from discard
			theCard = decks.getDiscard();
			cout << "Top of Discard Pile: ";
			theCard.print(); // Prints the top of discard pile

     			// displayer both "player's" hands
     			cout << "\n\nThe Player's Hand:\n";
     			theBoard.players[0].print();
     			cout << "\n\nOpponent's Hand:\n";
     			theBoard.players[1].print();

     			// present play options
			cout << "1. Pass" << endl;
			cout << "2. Take From Deck" << endl;
			cout << "3. Take From Discard" << endl;
			cout << "Please enter what you would like to do: ";
			cin >> playerChoice;
			
			while(true)
			{
				if(playerChoice < 1 || playerChoice > 3)
				{
					cout << "Please enter a valid choice: ";
					cin >> playerChoice;
				}
			}
			
			if(playerChoice == 1)
			{
				theBoard.pass(isPlayer);
			}
			else if(playerChoice == 2)
			{
				theBoard.takeFromDeck(isPlayer);	
			}
			else if(playerChoice == 3)
			{
				theBoard.takeFromDiscard(isPlayer);	
			}
			
			if(theBoard.players[0].isAllFaceUp() == true)
			{
				gameOn = false;
			}
			else
			{
				currentTurn++;	
			}
		}
		
		if(whoseTurn == 1) // Bots turn
		{
			botChoice = rand() % 3 + 1;
			isPlayer = false;
			
			if(playerChoice == 1)
			{
				theBoard.pass(isPlayer);
			}
			else if(playerChoice == 2)
			{
				theBoard.takeFromDeck(isPlayer);	
			}
			else if(playerChoice == 3)
			{
				theBoard.takeFromDiscard(isPlayer);	
			}
			
			if(theBoard.players[0].isAllFaceUp() == true)
			{
				gameOn = false;
			}
			else
			{
				currentTurn++;	
			}
		}
 	}
	
	cout << endl;
	cout << endl;
	
	playerScore = theBoard.players[0].score();
	botScore = theBoard.players[1].score();
	
	if(playerScore > botScore)
	{
		cout << "**Player Wins!!**" << endl;	
	}
	else if(botScore > playerScore)
	{
		cout << "**Opponent Wins...**" << endl;	
	}
	else
		cout << "**Tied Match**" << endl;
 

  	return 0; 
}
