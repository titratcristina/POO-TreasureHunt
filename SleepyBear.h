//
// Created by Cristina Titrat on 03/05/2020.
//

#ifndef POO_TREASUREHUNT_SLEEPYBEAR_H
#define POO_TREASUREHUNT_SLEEPYBEAR_H

#include "Seekers.h"

class SleepyBear : public Seekers {
public:
	explicit SleepyBear(const Game &G);		// explicit constructor for second player
	virtual ~SleepyBear();					// virtual destructor
	void move(const Game &G) override;  	// override movement method for second player
};


#endif //POO_TREASUREHUNT_SLEEPYBEAR_H
