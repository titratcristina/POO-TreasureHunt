//
// Created by Cristina Titrat on 03/05/2020.
//

#include "CrazyBee.h"

// constructor for seeker Crazy Bee
CrazyBee::CrazyBee(const Game &G) : Seekers(G) {
	position.row = position.column = 0;    	  // initial position is (0, 0)
	direction = 1;                            // direction is used for movement on the map
	stuck = false;                            // at the beginning the player isn't stuck
	index = 1;                                // he has index 1 because he is first
}

// movement method for first player
void CrazyBee::move(const Game &G) {
	// CrazyBee is going down then to the right, forming an L
	if (direction == 1 && position.row + 1 >= 0 && position.row + 1 < G.size &&
		(G.map[position.row + 1][position.column] == 0 || G.map[position.row + 1][position.column] == 5)) {

		// down
		position.row += 1;

	} else if (position.column + 1 >= 0 && position.column + 1 < G.size &&
			   (G.map[position.row][position.column + 1] == 0 || G.map[position.row][position.column + 1] == 5)) {

		// right
		direction = -1;
		position.column += 1;

	} else {
		stuck = true;  // if there is no other way to move the player is stuck
	}
}

// default destructor for seeker Crazy Bee
CrazyBee::~CrazyBee() = default;
