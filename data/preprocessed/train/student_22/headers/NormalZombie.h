#pragma once
#include "Zombie.h"
class NormalZombie : public Zombie
{
public:
	NormalZombie() = delete;
	NormalZombie(int x, int y, std::list<Entity*>& aList, std::list<Entity*>& plants) :
		Entity(x, y, aList),Zombie(x,y,aList,10,'Z',MoveableObject::Directions::LEFT,10, plants) {}

	~NormalZombie() {}


	void update() override
	{
		Zombie::update();
	}

};

