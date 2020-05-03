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
