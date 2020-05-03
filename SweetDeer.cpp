//
// Created by Cristina Titrat on 03/05/2020.
//

#include "SweetDeer.h"

// constructor for seeker Sweet Deer
SweetDeer::SweetDeer(const Game &G) : Seekers(G) {
	position.row = 0;                // initial position is (0, size - 1)
	position.column = G.size - 1;
	stuck = false;                    // at the beginning the player isn't stuck
	index = 4;                        // he has index 4 because he is fourth
}

// movement method for fourth player
void SweetDeer::move(const Game &G) {
	// Sweet Deer is jumping across the forest in zig-zag
	if (position.column - 2 >= 0 && position.row - 2 >= 0 &&
		(G.map[position.row - 2][position.column - 2] == 0 ||
		 G.map[position.row - 2][position.column - 2] == 5)) {

		// left down
		position.column -= 2;
		position.row -= 2;

	} else if (position.row + 2 < G.size && position.column - 2 >= 0 &&
			   (G.map[position.row + 2][position.column - 2] == 0 ||
				G.map[position.row + 2][position.column - 2] == 5)) {

		// left up
		position.row += 2;
		position.column -= 2;

	} else {
		stuck = true;    // if there is no other way to move the player is stuck
	}
}

// default destructor for seeker Sweet Deer
SweetDeer::~SweetDeer() = default;
