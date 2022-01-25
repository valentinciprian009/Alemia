#include"Sunflower.h"

void Sunflower::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << "&";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "|";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "~";
}

int Sunflower::printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	if (!canPlant)
	{
		int cooldwn = cooldown - duration_cast<seconds>(steady_clock::now() - lastPlantedTime).count();
		if (cooldwn > 0)
			return cooldwn;
		else
		{
			canPlant = 1;
			return 0;
		}
	}
	else
		return 0;
}

bool Sunflower::canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	if (!canPlant)
		if (duration_cast<seconds>(steady_clock::now() - lastPlantedTime).count() < cooldown)
			return false;
		else
		{
			canPlant = 1;
			return true;
		}
	else
		return true;
}

void Sunflower::plant(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	canPlant = 0;
	setLastPlantedTime(lastPlantedTime, steady_clock::now());
}

void Sunflower::ability(SunGround& sunGround)
{
	sunGround.reduceTimeInterval(RATE);
}