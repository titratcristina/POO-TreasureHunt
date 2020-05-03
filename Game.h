//
// Created by Cristina Titrat on 01/05/2020.
//

#ifndef POO_TREASUREHUNT_GAME_H
#define POO_TREASUREHUNT_GAME_H

class Game {
private:
	int **map;        			// allocate dynamically a 2D matrix
	int size;        			// map size
	int diamonds;    			// represents the number of diamonds/treasures found
	int *inGame;    			// mark the players who are in the game
	int winner;    				// represents the index of the winning Seeker
};

#endif //POO_TREASUREHUNT_GAME_H
