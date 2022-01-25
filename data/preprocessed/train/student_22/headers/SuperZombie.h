#pragma once
#include "Zombie.h"
class SuperZombie : public Zombie
{
public:
	SuperZombie() = delete;
	SuperZombie(int x, int y, std::list<Entity*>& aList, int damage, char img, Directions dir, int hp, std::list<Entity*>& plants) :
		Entity(x, y, aList), Zombie(x, y, aList, damage, img, dir, hp, plants) {}

	~SuperZombie() {}


	void update() override
	{
		MoveableObject::update();
		Drawnable::update();
		LifeForm::update();
	}
};

