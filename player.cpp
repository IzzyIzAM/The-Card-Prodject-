#include <iostream>
using namespace std;

class player {
private:
	card hand[2][3];
	bool cardvisable[2][3];
	bool isPlayer;
public:
	//initializes a empty player
	player() {
		
	}

	void setHand(card arry[6]) {
		//sets all of the cards to the apropriate cards
		int index = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++) {
				hand[i][j].setCard(arry[index].cardType());
				cardvisable[i][j] = false;
				index++;
			}
	}

	void placeCard(card theCard, int r, int c) {
		hand[r][c] = theCard;
		cardvisable[r][c] = true;
	}

	card getCard(int r, int c) {
		//returns the card if its facing up
		card ret(15);
		if (cardvisable[r][c])
		{
			return hand[r][c];
		}
		return ret;
	}
	 
	void print() {
		//prints the players hand
		card ret(15);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (cardvisable[i][j])
					hand[i][j].print();
				else
					ret.print();
			}
			cout << endl;
		}
	}

};
