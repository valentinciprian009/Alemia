#include "SnowProjectile.h"
#include "ConsoleOutput.h"
#include "Terrain.h"

void SnowProjectile::draw(int x, int y)
{
	if (y > 8)
		return;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(11 + 6 * x, 20 + 15 * y + 7, 144) << "  ";
	this->x = x;
	this->y = y;
}
