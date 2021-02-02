#pragma once
#include "Sun.h"
#include"ConsoleInput.h"
#include"ConsoleOutput.h"

#define ROW_TITLE					60			
#define COL_FIRST_STAR_POSITION		60
#define COL_DISTANCE_BETWEEN_STARS	1
#define COL_START 1
#define ROW_START 1

class Zombie
{
public:
	Zombie();

	void drawTheZombie();

	void appear();

	int zombieLife();

	/*ostream& operator<<(ostream &out,const Zombie& zomb) {
		out << zomb.appear();
		return out;
	} */

	~Zombie();
};

