#pragma once
#include "Plant.h"
#include "PeaProjectile.h"
#include <string>


class Peashooter :
	public Plant
{
	PeaProjectile projectile;
public:
	Peashooter();
	void draw(int x, int y);
	void draw(int y);
	std::string identity();
	void useSkill();
};

