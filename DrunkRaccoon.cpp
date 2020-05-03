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

// movement method for third player
void DrunkRaccoon::move(const Game &G) {
	// DrunkRaccoon is moving on diagonally
	if (direction == 1 && position.column - 1 >= 0 && position.row - 1 >= 0 &&
		(G.map[position.row - 1][position.column - 1] == 0 ||
		 G.map[position.row - 1][position.column - 1] == 5)) {

		// going up diagonally
		position.column -= 1;
		position.row -= 1;

	} else if (position.row + 1 >= 0 && position.row + 1 < G.size &&
			   (G.map[position.row + 1][position.column] == 0 ||
				G.map[position.row + 1][position.column] == 5)) {

		// going to right
		direction = -1;
		position.row += 1;

	} else {
		stuck = true;    // if there is no other way to move the player is stuck
	}
}

// default destructor for seeker Drunk Raccoon
DrunkRaccoon::~DrunkRaccoon() = default;
