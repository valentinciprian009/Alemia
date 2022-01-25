#pragma once
#include "LifeForm.h"
#include "Drawnable.h"
#include "Entity.h"
class Plants: public LifeForm, public Drawnable
{
public:
	Plants() = delete;
	Plants(int x, int y, std::list<Entity*>& aList, int damage, char img,int hp):
		Entity(x, y, aList), Drawnable(x, y, aList, img),LifeForm(x, y, aList, hp) {}
	~Plants(){}

	void update() override
	{
		Drawnable::update();
		LifeForm::update();
	}

};

