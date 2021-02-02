#pragma once
#include "CPlants.h"
class CPlant_CherryBomb :
	public CPlants
{
	bool attacker;

	//PlantType Type_;
public:
	CPlant_CherryBomb(int cost, int lifeResistance, int shooting_frequency) : CPlants(cost, lifeResistance, shooting_frequency) { this->attacker = 1;  
	CLog::getInstance().printLog("S-a apelat constructorul clasei CPlant_CherryBomb\n");
	};
	virtual ~CPlant_CherryBomb();
	void Draw(int x, int y) override;
	bool Attacker_or_not() override;
};

