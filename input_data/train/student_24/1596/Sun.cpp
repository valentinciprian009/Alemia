#include "Sun.h"

Sun::Sun(int x, int y, int val) : Resource(x, y, val), Entity(x, y)
{
	this->colors.push_back(14);
}


void Sun::print() const
{
	const char ray = 248;
	const char middle = 233;

	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut.setColor(*this->colors.begin());

	conOut(coordX, coordY) << ray;
	conOut(coordX, coordY + 1) << ray;
	conOut(coordX, coordY + 2) << ray;
	conOut(coordX + 1, coordY - 1) << ray;
	conOut(coordX + 1, coordY + 1) << middle;
	conOut(coordX + 1, coordY + 3) << ray;
	conOut(coordX + 2, coordY) << ray;
	conOut(coordX + 2, coordY + 1) << ray;
	conOut(coordX + 2, coordY + 2) << ray;
}

Sun::~Sun()
{
	this->colors.clear();
}