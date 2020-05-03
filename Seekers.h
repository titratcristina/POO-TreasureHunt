//
// Created by Cristina Titrat on 01/05/2020.
//

#ifndef POO_TREASUREHUNT_SEEKERS_H
#define POO_TREASUREHUNT_SEEKERS_H

struct Position {
	int row, column;
};

class Seekers {
protected:
	Position position{};
	int index{};
	bool stuck{};

};


#endif //POO_TREASUREHUNT_SEEKERS_H
