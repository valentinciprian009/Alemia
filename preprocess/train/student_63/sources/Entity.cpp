#include "Entity.h"


void const Entity::Draw()
{
	ConsoleHandler&out = ConsoleHandler::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	out(x, y) << img;
	out.releaseInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	out(x + 1, y) << " ";
}
void const Entity::clearOld()
{
	ConsoleHandler&out = ConsoleHandler::getInstance();
	out(x, y) << " ";
	//out.releaseInstance();
}


Entity::Entity(char img1, int x1, int y1, int color1)
{
	img = img1;
	x = x1;
	y = y1;
	color = color1;

}

void Entity::setX(int newX)
{
	ConsoleHandler& out = ConsoleHandler::getInstance();
	x = newX;
	//out.releaseInstance();
}
void Entity::setY(int newY)
{
	ConsoleHandler&out = ConsoleHandler::getInstance();
	y = newY;
	//out.releaseInstance();
}
Entity::~Entity()
{
	//clearOld();
}
