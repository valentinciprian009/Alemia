#pragma once
#include "Plants.h"
#include "Pea.h"
class PeaShooter : public Plants
{
	std::list<Entity*>& bullets;
	std::list<Entity*>& zombies;
	int delay = 0;
public:
	PeaShooter() = delete ;
	PeaShooter(int x, int y, std::list<Entity*>& aList, std::list<Entity*>& bullets,
		std::list<Entity*>& zombies): bullets(bullets), zombies(zombies),
		Entity(x, y, aList), Plants(x,y,aList,3,'P',10) {}
	~PeaShooter(){}

	void update() override
	{
		for (auto i : zombies)
		{
			if (getY() == i->getY())
			{
				if (delay == 10)
				{
					bullets.push_back(new Pea(getX() + 1, getY(), bullets, '*', MoveableObject::Directions::RIGHT, zombies));
					delay = 0;
				}
				break;
			}
		}
		delay++;
		Drawnable::update();
		LifeForm::update();
	}
};

