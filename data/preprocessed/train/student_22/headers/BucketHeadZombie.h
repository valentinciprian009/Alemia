#pragma once
#include "Zombie.h"
class BucketHeadZombie : public Zombie
{
public:
	BucketHeadZombie() = delete;
	BucketHeadZombie(int x, int y, std::list<Entity*>& aList, int damage, char img, Directions dir, int hp, std::list<Entity*>& plants) :
		Entity(x, y, aList), Zombie(x, y, aList, damage, img, dir, hp, plants) {}

	~BucketHeadZombie() {}


	void update() override
	{
		MoveableObject::update();
		Drawnable::update();
		LifeForm::update();
	}
};

