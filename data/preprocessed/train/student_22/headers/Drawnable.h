#pragma once
#include "Entity.h"
#include "ConsoleHandler.h"
class Drawnable: virtual public Entity
{
	ConsoleHandler& myHandler = ConsoleHandler::getInstance();
	char img;
public:
	Drawnable() = delete;
	Drawnable(int x, int y, std::list<Entity*>& aList,char img):
		Entity(x, y, aList),
	img(img){}

	void update() override
	{
		draw();
	}
	~Drawnable() {}
private:
	void draw()
	{
		myHandler(getX(), getY()) << ' '  << img << ' ';
	}
	
};

