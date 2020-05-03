//
// Created by Cristina Titrat on 03/05/2020.
//

#include "DrunkRaccoon.h"
// constructor for seeker Drunk Raccoon
DrunkRaccoon::DrunkRaccoon(const Game &G) : Seekers(G) {
	position.row = G.size - 1;    // initial position is (size-1, size-1)
	position.column = G.size - 1;
	direction = 1;                            // direction is used for movement on the map
	stuck = false;                    // at the beginning the player isn't stuck
	index = 3;                        // he has index 3 because he is third
}
