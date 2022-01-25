#pragma once
#include "Plants.h"
class CherryBomb: public Plants
{
public:
	CherryBomb() = delete;
	CherryBomb(int x, int y, std::list<Entity*>& aList, int damage, char img, int hp) :
		Entity(x, y, aList), Plants(x, y, aList, damage, img, hp) {}
	~CherryBomb() {}
	
	void update() override
	{
		Drawnable::update();
		LifeForm::update();
	}
};

