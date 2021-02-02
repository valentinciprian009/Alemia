#pragma once
#include"CLevel.h"
class CPlants
{
protected:
	
protected:
	int Cost_;
	int ShootingFrequency_;
	int LifeResistance_;

public:
	CPlants(int cost, int LifeResistance, int shooting_frequency);
	virtual ~CPlants();
	int GetPlantValue();
	virtual void Draw(int x, int y);
	virtual bool Attacker_or_not();
	static string FilePlantationsCoord;
};