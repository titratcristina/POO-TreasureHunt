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
