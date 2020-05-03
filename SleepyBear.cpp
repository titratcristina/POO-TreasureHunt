//
// Created by Cristina Titrat on 03/05/2020.
//

#include "SleepyBear.h"

// constructor for seeker Sleepy Bear
SleepyBear::SleepyBear(const Game &G) : Seekers(G) {
	position.row = G.size - 1;            // initial position is (size - 1, 0)
	position.column = 0;
	stuck = false;                    // at the beginning the player isn't stuck
	index = 2;                        // he has index 2 because he is second
}

// movement method for second player
void SleepyBear::move(const Game &G) {
	// SleepyBear is so lazy that he is skipping a line

	if (position.column + 2 >= 0 && position.column + 2 < G.size &&
		(G.map[position.row][position.column + 2] == 0 ||
		 G.map[position.row][position.column + 2] == 5)) {

		// left
		position.column += 2;

	} else {
		stuck = true;  // if there is no other way to move the player is stuck
	}
}

// default destructor for seeker Sleepy Bear
SleepyBear::~SleepyBear() = default;
