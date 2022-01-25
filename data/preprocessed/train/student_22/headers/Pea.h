#pragma once
#include "Drawnable.h"
#include "MoveableObject.h"
#include "LifeForm.h"

class Pea : public Drawnable, public MoveableObject
{
	std::list<Entity*>& zombies;
public:
	Pea() = delete;
	Pea(int x, int y, std::list<Entity*>& aList,  char img, Directions dir, std::list<Entity*>& zombies) : zombies(zombies),
		Entity(x, y, aList), Drawnable(x, y, aList, img), MoveableObject(x, y, aList, dir){}

	~Pea() {}


	void update() override
	{
		for (auto i : zombies)
		{
			if ((getX() == i->getX() || getX() == i->getX() -1 || getX() == i->getX() + 1) && getY() == i->getY())
			{
				destroyOnNextCall();
				dynamic_cast<LifeForm*>(i)->takedmg(2);
			}
		}
		MoveableObject::update();
		Drawnable::update();  
		Entity::update();
	}
};