#include "Sunflower.h"
#include "Game.h"

Sunflower::Sunflower(int x, int y, int price) : Plant(x, y, 50, price), BattleEntity(x, y, 50), Entity(x, y), hasActed(false)
{
	this->colors.push_back(14);
}

iPlant* Sunflower::clone()
{
	return new Sunflower(*this);
}

Sunflower::~Sunflower()
{
	this->colors.clear();
}

void Sunflower::print() const
{
	const char ray = 248;
	const char middle = 233;
	const char body = 197;

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
	conOut(coordX + 3, coordY + 1) << body;
}

void Sunflower::action() 
{
	if ((Game::getIteration() % 30) != 0)
		return;
	if (hasActed == false)
	{
		Game::addResourceFreq(-20);
		Game::setResourceVal(50);
		hasActed = true;
	}
}
