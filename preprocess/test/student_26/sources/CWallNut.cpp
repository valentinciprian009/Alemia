#include "CWallNut.h"



void CWallNut::draw()
{
}

void CWallNut::deletepos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "        ";
}


CWallNut::CWallNut()
{
	this->price = 50;
}
CWallNut::CWallNut(int x, int y)
{
	this->x = x;
	this->y = y;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	this->hp = 100;
	this->name = "W";
	this->price = 50;
	conOut(x, y) << "WALL-NUT";
}


CWallNut::~CWallNut()
{
}
