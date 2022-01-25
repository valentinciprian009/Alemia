#pragma once
#include "Plants.h"
class WallNut: public Plants
{
public:
	WallNut() = delete;
	WallNut(int x, int y, std::list<Entity*>& aList, int damage, char img, int hp) :
		Entity(x, y, aList), Plants(x, y, aList, damage, img, hp) {}
	~WallNut() {}

	void update() override
	{
		Drawnable::update();
		LifeForm::update();
	}

};

