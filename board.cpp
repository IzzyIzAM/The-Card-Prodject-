#include <iostream>
#include "deck.h"
#include "board.h"
#include "player.h"
using namespace std;

	Board::Board(int numOfPlayers) 
	{
		// dynamically allocate players
		players = new player[numOfPlayers];
		this->numOfPlayers = numOfPlayers;
		scoreboard = new int[numOfPlayers];

		// initialize deck
		TheDeck = new deckOfCards(numOfPlayers);
	}

	card Board::draw()
	{
		// draws the table
		return TheDeck->draw();
	};

	void Board::pass(bool isPlayer)
	{
		
		bool isFlipped = false;
		int row_choice, col_choice;
		int randomRow, randomCol;

		// draws : Takes a card from the top of the deck and
		// puts it in discard stash
		if(isPlayer == true) {
			TheDeck->setDiscard(TheDeck->draw());
			cout << "Please enter a row number(between 1-2): ";
			cin >> row_choice;
			cout << "Please enter a col number(between 1-3): ";
			cin >> col_choice;
			
			isFlipped = players[0].flip(row_choice-1, col_choice-1);
			
			while(!isFlipped)
			{
				cout << "This card is already facing up." << endl;
				cout << "Please re-enter a row number(between 1-2): ";
				cin >> row_choice;
				cout << "Please re-enter a col number(between 1-3): ";
				cin >> col_choice;

				isFlipped = players[0].flip(row_choice-1, col_choice-1);
			}
		}
		//BOTS CHOICE	
		else
		{
			TheDeck->setDiscard(TheDeck->draw());
			randomRow = rand()%2;
			randomCol = rand()%3;
			
			isFlipped = players[1].flip(randomRow-1, randomCol-1);
			
			while (!isFlipped)
			{
				randomRow = rand() % 2;
				randomCol = rand() % 3;
				isFlipped = players[1].flip(randomRow-1, randomCol-1);
			}
		}	
	}

	void Board::deal()
	{
		// initialize hand to pass to player
		card array[6];
		// for each player, draw 6 cards and
		// pass them their new hand
		for (int i = 0; i < numOfPlayers; i++)
		{
			// get new hand
			for (int j = 0; j < 6; j++) {
				array[j].setCard(TheDeck->draw());
			}
			// set player's hand
			players[i].setHand(array);
		}
	}

	card Board::takeFromDeck(bool isPlayer)
	{
	
		card TheCard;

		bool isFlipped = false;
		int user_choice;
		int row_choice, col_choice, bot_choice_row, bot_choice_col, bot_choice;

		TheCard = TheDeck->draw();

		if(isPlayer)
		{
			cout << "The card that you pulled is: ";
			TheCard.print();

			cout << "Please choose an option: (1) Swap card or (2) Discard card" << endl;
			cin >> user_choice;

			if (user_choice == 1)
			{
				cout << "Please enter a row number(between 1-2): ";
				cin >> row_choice;
				cout << "Please enter a col number(between 1-3): ";
				cin >> col_choice;
				
				isFlipped = players[0].flip(row_choice-1, col_choice-1);

				while (!isFlipped)
				{
					cout << "This card is already facing up." << endl;
					cout << "Please re-enter a row number(between 1-2): ";
					cin >> row_choice;
					cout << "Please re-enter a col number(between 1-3): ";
					cin >> col_choice;

					isFlipped = players[0].flip(row_choice-1, col_choice-1);
				}

				players[0].swap(row_choice-1, col_choice-1, TheCard);
			}
			else if (user_choice == 2)
			{
				TheDeck->setDiscard(TheCard);
			}
		}
		// BOT
		else
		{
			bot_choice  = rand() % 2 + 1;

			if (bot_choice == 1)
			{
				bot_choice_row = rand()% 2;
				bot_choice_col = rand()% 3;
				
				isFlipped = players[1].flip(bot_choice_row, bot_choice_col);

				while (!isFlipped)
				{
					bot_choice_row = rand() % 2;
					bot_choice_col = rand() % 3;

					isFlipped = players[1].flip(bot_choice_row, bot_choice_col);
				}

				players[1].swap(bot_choice_row, bot_choice_col, TheCard);
			}
			else if (bot_choice == 2)
			{
				TheDeck->setDiscard(TheCard);
			}
		}
	}

	card Board::takeFromDiscard(bool isPlayer)
	{
		
		card TheCard;
		int row_choice, col_choice, bot_choice_row, bot_choice_col;
		bool isFlipped = false;

		TheCard = TheDeck->getDiscard();

		if (isPlayer)
		{
			cout << "Please enter a row number(between 1-2): ";
			cin >> row_choice;
			cout << "Please enter a col number(between 1-3): ";
			cin >> col_choice;

			isFlipped = players[0].flip(row_choice-1, col_choice-1);

			while (!isFlipped)
			{
				cout << "This card is already facing up." << endl;
				cout << "Please re-enter a row number(between 1-2): ";
				cin >> row_choice;
				cout << "Please re-enter a col number(between 1-3): ";
				cin >> col_choice;

				isFlipped = players[0].flip(row_choice-1, col_choice-1);
			}
			players[0].swap(row_choice, col_choice, TheCard);

		}
		else{
			bot_choice_row = rand() % 2;
			bot_choice_col = rand() % 3;
			
			isFlipped = players[1].flip(bot_choice_row, bot_choice_col);

			while (!isFlipped)
			{
				bot_choice_row = rand() % 2;
				bot_choice_col = rand() % 3;

				isFlipped = players[1].flip(bot_choice_row, bot_choice_col);
			}
			players[1].swap(bot_choice_row, bot_choice_col, TheCard);
		}
	}

	int Board::getNumPlayers() { return numOfPlayers; };
