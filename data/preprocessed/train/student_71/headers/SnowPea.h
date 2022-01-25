#pragma once
#include "Plant.h"
#include "SnowProjectile.h"
#include <string>

class SnowPea:
	public Plant
{
	SnowProjectile projectile;
public:
	SnowPea();
	void draw(int x, int y);
	void draw(int y);
	std::string identity();
	void useSkill();
};

