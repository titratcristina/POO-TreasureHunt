//
// Created by Cristina Titrat on 03/05/2020.
//

#ifndef POO_TREASUREHUNT_DRUNKRACCOON_H
#define POO_TREASUREHUNT_DRUNKRACCOON_H


#include "Seekers.h"

class DrunkRaccoon : public Seekers {
private:
	int direction; 							// used for movement direction
public:
	explicit DrunkRaccoon(const Game &G);	// constructor for third player
	virtual ~DrunkRaccoon();				// virtual destructor
	void move(const Game &G) override;  	// override movement method for fourth player
};


#endif //POO_TREASUREHUNT_DRUNKRACCOON_H
