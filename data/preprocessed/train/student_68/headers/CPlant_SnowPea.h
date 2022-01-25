#pragma once
#include "CPlants.h"
class CPlant_SnowPea :
	public CPlants
{
	bool attacker_;

public:
	CPlant_SnowPea(int cost, int lifeResistance, int shooting_frequency) :CPlants(cost, lifeResistance, shooting_frequency) {
		this->attacker_ = 1;
		CLog::getInstance().printLog("S-a apelat constructorul clasei CPlant_SnowPea\n");
	};
	virtual ~CPlant_SnowPea();
	void Draw(int x, int y) override;
	bool Attacker_or_not() override;
};
