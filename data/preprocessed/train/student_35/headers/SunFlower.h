#pragma once
#include"LifeForm.h"
class SunFlower:public LifeForm
{
private:
	int cost;

public:
	SunFlower() {
		viata = 100;
		damage = 5;
		cost = 25;
		range = 30;
		icon = "S";
	}
	~SunFlower() {
		
	}
	int getCost() { return cost; }
};

