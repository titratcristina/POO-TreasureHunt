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

// a getter method for returning seeker's name based on index
const char *Seekers::getName(int i) {
	switch (i) {
		case 1:
			return "Crazy Bee";
		case 2:
			return "Sleepy Bear";
		case 3:
			return "Drunk Raccoon";
		case 4:
			return "Sweet Deer";
		default:
			return "Seeker";
	}
}
