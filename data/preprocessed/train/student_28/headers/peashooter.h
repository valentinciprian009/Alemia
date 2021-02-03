#pragma once
#include "Plant.h"
#include "bullet.h"
class peashooter:public Plant,public bullet
{
public:
	peashooter(int x,int y);
	peashooter();
	bullet* attack();
	void afiseaza(COORD pos);
};

