#include "Wallnut.h"

Wallnut::Wallnut(int x, int y, int pret) : Plant(x, y, 80, pret), BattleEntity(x, y, 80), Entity(x, y)
{
	this->colors.push_back(6);
}

Wallnut::~Wallnut()
{
	this->colors.clear();
}

void Wallnut::print() const
{
	const char piece = 219;

	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut.setColor(*this->colors.begin());

	conOut(coordX, coordY) << piece;
	conOut(coordX, coordY - 1) << piece;
	conOut(coordX + 1, coordY - 1) << piece;
	conOut(coordX + 1, coordY) << piece;
	conOut(coordX + 2, coordY) << piece;
	conOut(coordX + 2, coordY - 1) << piece;
	conOut(coordX, coordY) << piece;
	conOut(coordX, coordY + 1) << piece;
	conOut(coordX + 1, coordY + 1) << piece;
	conOut(coordX + 2, coordY + 1) << piece;
}

iPlant* Wallnut::clone()
{
	return new Wallnut(*this);
}
