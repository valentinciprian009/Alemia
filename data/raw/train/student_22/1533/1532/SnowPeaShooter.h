#pragma once
#include "Plants.h"
class SnowPeaShooter: public Plants
{
public:
	SnowPeaShooter() = delete;
	SnowPeaShooter(int x, int y, std::list<Entity*>& aList) :
		Entity(x, y, aList), Plants(x, y, aList, 5, 'S', 1) {}
	~SnowPeaShooter() {}

	void update() override
	{
		Drawnable::update();
		LifeForm::update();
	}
};



