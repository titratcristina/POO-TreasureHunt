//
// Created by Cristina Titrat on 01/05/2020.
//

#ifndef POO_TREASUREHUNT_GAME_H
#define POO_TREASUREHUNT_GAME_H

class Seekers; 					// forward declaration for Seekers class

class Game {
private:
	int **map;        			// allocate dynamically a 2D matrix
	int size;        			// map size
	int diamonds;    			// represents the number of diamonds/treasures found
	int *inGame;    			// mark the players who are in the game
	int winner;    				// represents the index of the winning Seeker

	Seekers *S[4]{};

	friend class Seekers;  		// change private inGame propertie of Game class
	friend class CrazyBee;  	// need to check and change private properties of Game class when players move
	friend class SleepyBear;
	friend class DrunkRaccoon;
	friend class SweetDeer;

public:
	explicit Game(int input);  	// constructor with parameter for user input size of map
	void showMap();        		// show map for one round
	int round(int input);		// playing a round
	bool isOver();        		// check to see if the game is over
	void playGame();        	// game management
	virtual ~Game();        	// game destructor
};


#endif //POO_TREASUREHUNT_GAME_H
