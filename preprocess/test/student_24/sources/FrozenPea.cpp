#include "FrozenPea.h"

FrozenPea::FrozenPea(int x, int y) : Projectile(x, y, 5, 25), movingEntity(x, y, 5), Entity(x, y) {}

FrozenPea::~FrozenPea()
{
	this->colors.clear();
}

void FrozenPea::print() const
{
	const char ch = 'O';

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(11);
	conOut(coordX, coordY) << ch;
}