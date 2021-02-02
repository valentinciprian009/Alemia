#include "Pea.h"

Pea::Pea(int x, int y) : Projectile(x, y, 5, 50), Entity(x, y), movingEntity(x, y, 5)
{
	this->colors.push_back(10);
}

Pea::~Pea()
{
	this->colors.clear();
}

void Pea::print() const
{
	const char ch = 'O';

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(10);
	conOut(coordX, coordY) << ch;
}