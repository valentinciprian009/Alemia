#pragma once
#include "Plant.h"
#include <string>

class Wallnut :
	public Plant
{
public:
	Wallnut();
	void draw(int x, int y);
	void draw(int y);
	std::string identity();
	void useSkill() {}; // He literally does nothing, he is a wall
};

