#pragma once
#include <list>
#include "Point.h"
#include "ConsoleHandler.h"
class Entity
{
	bool isDead=false;
	Point position;
	std::list<Entity*>& aList;
public:
	Entity() = delete;
	Entity(int x, int y, std::list<Entity*>& aList):
		position(x,y), aList(aList) {}
	virtual ~Entity()
	{
		removeSelfFromList();
		ConsoleHandler& myh = ConsoleHandler::getInstance();
		myh(getX() - 1, getY()) << "   ";
		myh.releaseInstance();
	}
	virtual void update()
	{
		if (getX() >= 99)
			isDead = true;
		if (isDead)
		{
			delete this;
		}
	}

	 void setX(int x)
	 {
		 position.setX(x);
	 }
	 void setY(int y)
	 {
		 position.setY(y);
	 }
	 int getX()
	 {
		 return position.getX();
	 }
	 int getY()
	 {
		 return position.getY();
	 }
	 void destroyOnNextCall()
	 {
		 isDead = true;
	 }

private:
	void removeSelfFromList()
	{
		aList.remove(this);
	}
};

