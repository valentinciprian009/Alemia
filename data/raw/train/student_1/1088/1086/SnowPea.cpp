#include"SnowPea.h"

void SnowPea::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft + 0) << "*@=";
	consoleOut(rowUpperLeft + 1, colUpperLeft + 1) << "|";
	consoleOut(rowUpperLeft + 2, colUpperLeft + 1) << "~";
}

int SnowPea::printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

bool SnowPea::canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

void SnowPea::plant(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	canPlant = 0;
	setLastPlantedTime(lastPlantedTime, steady_clock::now());
}

void SnowPea::ability()
{
	frozenPea.shoot();
}

bool SnowPea::hitZombie(Zombie* zombie)
{
	frozenPea.hitZombie(zombie);
	if (zombie->die())
		return true;
	return false;
}

bool SnowPea::getHitZombie(Zombie* zombie)
{
	if (zombie)
	{
		if ((zombie->getColUpperLeft() == colUpperLeft + 3) && (zombie->getRowUpperLeft() == rowUpperLeft))
		{
			if ((zombie->getType() == 1) || (zombie->getType() == 2))
			{
				zombie->setStop(colUpperLeft + 3);
				zombie->hit(currentHP);
			}
			else
			{
				if (zombie->checkJump())
				{
					zombie->vault();
				}
				else
				{
					zombie->setStop(colUpperLeft + 3);
					zombie->hit(currentHP);
				}
			}
		}
	}
	if (die())
	{
		consoleOut(frozenPea.getRowUpperLeft(), frozenPea.getColUpperLeft() - 1) << " ";
		return true;
	}
	return false;
}