#pragma once
#include "Draw.h"
class Frozen_Pea:public Draw
{
	int power;
public:
	Frozen_Pea();
	Frozen_Pea(int power) :power(power) {};
	void draw(int x, int y);
	~Frozen_Pea();
};

