#pragma once
#include "Plant.h"
#include "Fire.h"
#include <vector>
class Peashoter :
	public Plant
{
	std::vector<Fire*> bulets;
public:
	Peashoter(char img1, int x1, int y1, int color1, int hp);
	void update();
	~Peashoter();
};

