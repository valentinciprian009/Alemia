#include "CSunFlower.h"


void CSunFlower::deletepos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "         ";
}

CSunFlower::CSunFlower(int x, int y)
{
	this->x = x;
	this->y = y;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	this->hp = 50;
	this->name = "S";
	this->price = 50;
	conOut(x, y) << "SUNFLOWER";
}


CSunFlower::CSunFlower()
{	
	this->price = 50;
}


CSunFlower::~CSunFlower()
{
}
