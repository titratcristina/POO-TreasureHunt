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

// a method to show if a player found a diamond or got stuck
void Seekers::getStatus(const Game &G) {
	if (stuck) {
		cout << "The player " << "(" << index << ") ";
		cout << getName(index) << " got stuck in a tree\n";
	} else if (!isPlaying(G)) {
		cout << "The player " << "(" << index << ") ";
		cout << getName(index) << " found a diamond.\n";
	}
}

// a bool method for checking if seeker is stuck on the map
bool Seekers::isStuck() {
	return stuck;
}

// a bool method for checking if seeker is still on the map or not
bool Seekers::isPlaying(const Game &G) {
	return G.inGame[getIndex()];
}

// a method to stop seeker when he gets stuck or finds a diamond
void Seekers::stopPlayer(Game &G) {
	G.inGame[getIndex()] = 0;
}

// default destructor for seekers
Seekers::~Seekers() = default;
