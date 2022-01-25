#include "CPeaShooter.h"

CPeaShooter::CPeaShooter(int x, int y)
{
	this->hp = 70;
	this->name = "P";
	this->price = 100;
	this->x = x;
	this->y = y;
	draw();
}
void CPeaShooter::deletepos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "          ";
}
void CPeaShooter::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y+1) << "PEASHOT";
}
CPeaShooter::CPeaShooter()
{
	this->price = 100;
}

CPeaShooter::~CPeaShooter()
{
}
