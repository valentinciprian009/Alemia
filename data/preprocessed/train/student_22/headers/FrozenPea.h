#pragma once
#include "Drawnable.h"
#include "MoveableObject.h"
class FrozenPea: public Drawnable , public MoveableObject
{
public:
	FrozenPea() = delete;
	FrozenPea(int x, int y, std::list<Entity*>& aList, char img, Directions dir) :
		Entity(x, y, aList), Drawnable(x, y, aList, img), MoveableObject(x, y, aList, dir) {}

	~FrozenPea() {}
	void update() override
	{
		MoveableObject::update();
		Drawnable::update();
	}

};

