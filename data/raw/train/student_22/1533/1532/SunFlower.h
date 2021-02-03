#pragma once
#include "Plants.h"
class SunFlower: public Plants
{
public:
	SunFlower() = delete;
	SunFlower(int x, int y, std::list<Entity*>& aList, int damage, char img, int hp) :
		Entity(x, y, aList), Plants(x, y, aList, damage, img, hp) {}
	~SunFlower() {}

	void update() override
	{
		Drawnable::update();
		LifeForm::update();
	}
};
	


