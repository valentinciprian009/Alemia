#include"CherryBomb.h"

void CherryBomb::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << "  ";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << " /\\";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "O  O";
}

int CherryBomb::printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

bool CherryBomb::canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

void CherryBomb::plant(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	canPlant = 0;
	setLastPlantedTime(lastPlantedTime, steady_clock::now());
}

void CherryBomb::ability()
{
	//abilitate;
}