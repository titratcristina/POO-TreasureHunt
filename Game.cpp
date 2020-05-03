//
// Created by Cristina Titrat on 01/05/2020.
//

#include <iostream>
#include <cstdlib>		// for rand() function
#include <ctime>		// for time function
#include "Game.h"
#include "Seekers.h"

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
}


// playing a round
int Game::round(int input) {
	if (input == 0) {
		return 0;        // stop the game if input is 0
	} else {
		for (int i = 0; i < 4; i++) {
			// checking players for being in game
			if (S[i]->isPlaying(*this)) {
				auto *initP = new Position;    	// initial position of player
				*initP = S[i]->getPosition();
				S[i]->move(*this);          	// if it possible move player

				auto *P = new Position;			// new position of player
				*P = S[i]->getPosition();		// after movement new position is store

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
