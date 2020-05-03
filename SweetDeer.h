//
// Created by Cristina Titrat on 03/05/2020.
//

#ifndef POO_TREASUREHUNT_SWEETDEER_H
#define POO_TREASUREHUNT_SWEETDEER_H

#include "Seekers.h"

class SweetDeer : public Seekers {
public:
	explicit SweetDeer(const Game &G);		// constructor for fourth player
	virtual ~SweetDeer();					// virtual destructor
	void move(const Game &G) override;  	// override movement method for fourth player
};


#endif //POO_TREASUREHUNT_SWEETDEER_H
