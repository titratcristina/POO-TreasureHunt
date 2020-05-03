//
// Created by Cristina Titrat on 01/05/2020.
//

#include <iostream>
#include "Seekers.h"

using namespace std;

// default constructor for seekers
Seekers::Seekers(const Game &G) {
}

// a getter method for returning seeker's index
int Seekers::getIndex() {
	return index;
}

// a getter method for returning seeker's current position
Position Seekers::getPosition() {
	return position;
}
