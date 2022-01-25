#pragma once
#include "Entity.h"
class LifeForm: virtual public Entity
{
	int hp;
public:
	LifeForm() = delete;
	LifeForm(int x, int y, std::list<Entity*>& aList,int hp): hp(hp),
		Entity(x, y, aList) {}
	~LifeForm() {}
	void update() override
	{
		if (hp <= 0)
			destroyOnNextCall();
		Entity::update();
	}
	void takedmg(int dmg)
	{
		hp-=dmg;
	}
};

