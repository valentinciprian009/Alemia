#pragma once
#include "CPlants.h"
class CPlant_Sunflower :
	public CPlants
{
	bool attacker_;

	//PlantType Type_;
public:
	CPlant_Sunflower(int cost, int lifeResistance, int shooting_frequency) :CPlants(cost, lifeResistance, shooting_frequency) {
		this->attacker_ = 0;
		CLog::getInstance().printLog("S-a apelat constructorul clasei CPlant_SnowPea\n");
	};
	virtual ~CPlant_Sunflower();
	static bool status_;
	void Draw(int x, int y)override;
	bool Attacker_or_not() override;
};

