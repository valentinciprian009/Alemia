#pragma once
#include "Entity.h"
class MoveableObject :virtual public Entity
{
public:enum class Directions {
	UP, DOWN, LEFT, RIGHT
};
private:
	Directions currentDir;
public:
	MoveableObject() = delete;
	MoveableObject(int x, int y, 
		std::list<Entity*>& aList, 
		Directions direction):
		Entity(x, y, aList),
		currentDir(direction) {}
	~MoveableObject(){}
	void update() override
	{
		move();
	}
	void setdirection(Directions dir)
	{
		currentDir = dir;
	}
private:
	virtual void move()
	{
		switch (currentDir)
		{
		case Directions::DOWN:
		{
			setY(getY() + 1);
			break;
		}
		case Directions::UP:
		{
			setY(getY() - 1);
			break;
		}
		case Directions::LEFT:
		{
			setX(getX() - 1);
			break;
		}
		case Directions::RIGHT:
		{
			setX(getX() + 1);
			break;
		}
		default:
			break;
		}
	}
};

