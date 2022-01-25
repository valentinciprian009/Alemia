#pragma once

#include"CBullet.h"


class IPlants
{
public:
	static IPlants* createPlant(int cost, int LifeResistance, int shooting_frequency);
	virtual int GetPlantValue() = 0;
	virtual void Draw(int x, int y) = 0;
	virtual bool Attacker_or_not() = 0;
};

