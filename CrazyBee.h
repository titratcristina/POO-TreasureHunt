//
// Created by Cristina Titrat on 03/05/2020.
//

#ifndef POO_TREASUREHUNT_CRAZYBEE_H
#define POO_TREASUREHUNT_CRAZYBEE_H


#include "Seekers.h"

class CrazyBee : public Seekers {
private:
	int direction;  					// used for movement direction
public:
	explicit CrazyBee(const Game &G);	// explicit constructor for first player
	virtual ~CrazyBee();				// virtual destructor
	void move(const Game &G) override;  // override movement method for first player
};


#endif //POO_TREASUREHUNT_CRAZYBEE_H
