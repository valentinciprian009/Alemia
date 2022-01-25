#pragma once
#include "CPlants.h"
class CPlant_WallNut :
	public CPlants
{
	bool attacker_;

	//PlantType Type_;
public:
	CPlant_WallNut(int cost, int lifeResistance, int shooting_frequency) : CPlants(cost, lifeResistance, shooting_frequency) { this->attacker_ = 0;
	CLog::getInstance().printLog("S-a apelat constructorul clasei CPlant_SnowPea\n");
	};
	virtual ~CPlant_WallNut();
	void Draw(int x, int y)override;
	bool Attacker_or_not() override;
};

