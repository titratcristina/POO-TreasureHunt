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
