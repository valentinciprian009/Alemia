#include"Plant.h"

bool Plant::die()
{
	if (currentHP <= 0)
	{
		Log::getInstance().write("Plant Dead!");
		consoleOut(getRowUpperLeft() + 0, getColUpperLeft()) << "   ";
		consoleOut(getRowUpperLeft() + 1, getColUpperLeft()) << "   ";
		consoleOut(getRowUpperLeft() + 2, getColUpperLeft()) << "   ";
		return true;
	}
	return false;
}

bool Plant::getHitZombie(Zombie* zombie)
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
		return true;
	return false;
}