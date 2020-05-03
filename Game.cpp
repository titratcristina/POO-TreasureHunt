//
// Created by Cristina Titrat on 01/05/2020.
//

#include <iostream>
#include <cstdlib>		// for rand() function
#include <ctime>		// for time function
#include "Game.h"

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
