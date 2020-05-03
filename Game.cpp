//
// Created by Cristina Titrat on 01/05/2020.
//

#include <iostream>
#include <cstdlib>		// for rand() function
#include <ctime>		// for time function
#include "Game.h"
#include "Seekers.h"
#include "CrazyBee.h"
#include "SleepyBear.h"
#include "DrunkRaccoon.h"
#include "SweetDeer.h"

using namespace std;

// in this method the map is initialized
// the seekers are displayed on corners
// and the treasures are displayed on map randomly
Game::Game(int input) {
	size = input;
	map = new int *[size];					// dynamic allocation for map
	for (int i = 0; i < size; i++) {
		map[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = 0;                	// the map is initialized with 0
		}
	}

	// randomly place the 3 treasures on the map
	int i, j, treasures = 0;
	while (treasures < 3) {
		srand(time(nullptr));    	// initialize random seed
		i = rand() % size;        	// generate number between 1 and (size - 1)
		j = rand() % size;

		// i and j cannot be (0,0) (n,n), (0,n), (n,0)
		// position on map bust be 0 (0 means no element is there)
		if ((i || j) && !(i == size - 1 && j == size - 1) && !(i == 0 && j == size - 1) &&
			!(i == size - 1 && j == 0) && map[i][j] == 0) {
			map[i][j] = 5;        	// the treasure is marked with 5 on map, because index from 1 to 4 is for seekers
			treasures += 1;
		}
	}

	// set seekers position
	map[0][0] = 1;
	map[size - 1][size - 1] = 3;
	map[size - 1][0] = 2;
	map[0][size - 1] = 4;
	diamonds = 0;

	// mark all 4 seekers as being in the Game
	// a player is in game when it is marked with 1
	inGame = new int[4]{1, 1, 1, 1};
	winner = 0;        // at first winner must be 0

	// declaration of the 4 seekers
	S[0] = new CrazyBee(*this);
	S[1] = new SleepyBear(*this);
	S[2] = new DrunkRaccoon(*this);
	S[3] = new SweetDeer(*this);
}


// playing a round
int Game::round(int input) {
	if (input == 0) {
		return 0;        // stop the game if input is 0
	} else {
		for (int i = 0; i < 4; i++) {
			// checking players for being in game
			if (S[i]->isPlaying(*this)) {
				auto *initP = new Position;    		// initial position of player
				*initP = S[i]->getPosition();
				S[i]->move(*this);          	// if it possible move player

				auto *P = new Position;		// new position of player
				*P = S[i]->getPosition();	// after movement new position is store

				// check if the player found a diamond
				if (map[P->row][P->column] == 5) {
					diamonds += 1;                   	// increment the value of the treasures found variable
					S[i]->stopPlayer(*this);     	// takes the player out of the game
					map[P->row][P->column] = 6; 		// mark on the map the place were found treasures with 6
				} else {
					map[P->row][P->column] = S[i]->getIndex(); 	// mark on the map index of the player
				}

				// compare the initial position with actual position
				// if the initial position is not the same as actual position
				// (the player did not get stuck), the movement is displayed
				if (!(P->row == initP->row && P->column == initP->column)) {
					cout << "The player no. " << i + 1 << " is going from: (";
					cout << initP->row << ", " << initP->column << ") to (";
					cout << P->row << ", " << P->column << ")\n";
				}

				// if a player finds a treasure then he leaves the map
				if ((map[P->row][P->column]) == (5 + (S[i]->getIndex()))) {
					cout << "The player no. " << i + 1;
					cout << " will leave the Magic Forest.\n";
				}

				delete P;
				delete initP;
			}
		}

		// if a player finds a treasure return his index
		if (diamonds == 1) {
			// for each player check if he leaves the game
			for (int i = 0; i < 4; i++) {
				// if the player left the game
				if (!inGame[i]) {
					return i;  // return the winner index
				}
			}
		}

		return 0;
	}
}

// check to see if the game is over
bool Game::isOver() {
	// if were found all 3 diamonds the game is over
	if (diamonds == 3) {
		return true;
	} else {
		int playerStuck = 0;
		for (auto &i : S) {
			if (i->isStuck() == 1) {
				playerStuck++;    // check stuck players
			}
		}
		// if stuck players and diamonds found are in total 4, the game is over
		// (ex. 3 players are stuck and 1 player found a diamond => GAME OVER )
		if (playerStuck + diamonds == 4) {
			return true;
		}
	}
	return false;
}

// show map for one round
void Game::showMap() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == 5) {
				cout << "  \u2666  "; 		// the treasure will be displayed as a diamond ♦
			} else if (map[i][j] == 6) {
				cout << "  \u2605  "; 		// if a seeker found a diamond ♦, the place will be marked with a star
			} else if (map[i][j]) {
				cout << "  " << map[i][j] << "  "; 	// show number of player
			} else {
				cout << " \u2591\u2591\u2591 ";		// show a shadow
			}
		}
		cout << endl;
	}
	cout << endl;
}

// game management
void Game::playGame() {
	int input, indexWinner;
	cout << "This is the battlefield in the forest:\n";
	showMap();    // show initial map

	// ask user if he want to continue the game
	cout << "Do you want to continue? (YES->1, NO->0)\n";
	cin >> input;

	// while user's answer is YES, the game runs
	while (input) {
		indexWinner = round(input); 	// indexWinner gets index of winning player from previous round

		showMap();  					// show battlefield

		// the winner stores the index of first player that found the diamond
		if (indexWinner && (diamonds == 1)) {
			winner = indexWinner;
		}

		// if exists a winner show message down below
		if (winner) {
			cout << "The seeker no. " << winner << " is the winner! Player left the forest.\n";
		}

		// show status for every player
		for (auto &i : S) {
			i->getStatus(*this);
		}

		// when game is over, show finish message
		if (isOver()) {
			cout << "THE GAME IS OVER\n";
			input = 0;
		}

		// ask user if he want to continue the game
		if (input) {
			cout << "Do you want to continue? (YES->1, NO->0)\n";
			cin >> input;
		}
	}
}

// game destructor
Game::~Game() {
	for (int i = 0; i < size; i++) {
		delete[] map[i];    	// deallocates from memory columns
	}
	delete[] map;            	// deallocates from memory rows
	delete[] inGame;        	// deallocates from memory inGame array
}
