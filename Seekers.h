//
// Created by Cristina Titrat on 01/05/2020.
//

#ifndef POO_TREASUREHUNT_SEEKERS_H
#define POO_TREASUREHUNT_SEEKERS_H

#include "Game.h"

struct Position {
	int row, column;
};

class Seekers {
protected:
	Position position{};
	int index{};
	bool stuck{};
public:
	explicit Seekers(const Game &G);		// constructor for seekers
	virtual ~Seekers();						// destructor for seekers
	Position getPosition();  				// a getter method for returning seeker's current position
	int getIndex();  						// a getter method for returning seeker's index
	void getStatus(const Game &G);			// a method to show if a player found a diamond or got stuck
	bool isPlaying(const Game &G);  		// a method to show if a player found a diamond or got stuck
	bool isStuck();  						// a bool method for checking if seeker is stuck on the map
	void stopPlayer(Game &G);  				// a method to stop seeker when he gets stuck or finds a diamond
	static const char *getName(int i);		// a getter method for returning seeker's name based on index
	virtual void move(const Game &G) = 0;  	// a virtual method for movement

};


#endif //POO_TREASUREHUNT_SEEKERS_H
