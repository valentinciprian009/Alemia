#include"Peashooter.h"

void Peashooter::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << "@=";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "|";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "~";
}

int Peashooter::printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

bool Peashooter::canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime)
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

void Peashooter::plant(bool& canPlant, steady_clock::time_point& lastPlantedTime)
{
	canPlant = 0;
	setLastPlantedTime(lastPlantedTime, steady_clock::now());
}

void Peashooter::ability()
{
	pea.shoot();
}


bool Peashooter::hitZombie(Zombie* zombie)
{
	pea.hitZombie(zombie);
	if (zombie->die())
		return true;
	return false;
}

bool Peashooter::getHitZombie(Zombie* zombie)
{
	if (zombie)
	{
		if ((zombie->getColUpperLeft() == colUpperLeft + 3) && (zombie->getRowUpperLeft() == rowUpperLeft))
		{
			if (zombie->getType() != 3)
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
		consoleOut(pea.getRowUpperLeft(), pea.getColUpperLeft() - 1) << " ";
		return true;
	}
	return false;
}