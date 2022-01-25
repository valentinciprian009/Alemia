#pragma once
#include"LifeForm.h"
class PeaShooter:public LifeForm
{
protected:
	int cost;
public:
	PeaShooter() {
		viata = 130;
		damage = 20;
		cost = 50;
		range = 100;
		icon = "PS";
	}
	~PeaShooter() {}
	int getCost() { return cost; }
};

