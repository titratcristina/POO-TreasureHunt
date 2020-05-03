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

}
