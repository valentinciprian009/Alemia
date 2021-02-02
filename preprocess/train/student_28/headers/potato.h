#pragma once
#include "Plant.h"
#include <iostream>
class potato:public Plant
{public:
	potato(int x, int y);
	void afiseaza(COORD pos);
	void sterge(COORD pos);
	void gotoxy(int x, int y);
};

