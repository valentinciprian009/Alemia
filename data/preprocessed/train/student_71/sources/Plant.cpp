#include "Plant.h"
#include "Terrain.h"


void Plant::damage(int x, bool slowed)
{
	bitesCount--;
	if (!isAlive())
	{
		Terrain& terrain = Terrain::getInstance();
		terrain.destroy(this->getX(), this->getY());
	}
}

void Plant::setStrength(int x)
{
	bitesCount = x;
}

void Plant::setPrice(int x)
{
	price = x;
}

int Plant::getPrice()
{
	return price;
}

bool Plant::isAlive()
{
	if (!bitesCount)
		return false;
	return true;
}

time_point<steady_clock> Plant::getTimer()
{
	return skillTimer;
}

time_point<steady_clock> Plant::resetTimer()
{
	return skillTimer = steady_clock::now();
}
