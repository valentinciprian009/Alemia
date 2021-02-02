#include"Pea.h"

void Pea::shoot()
{
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > MOVE_TIME))
	{
		begin = end;
		consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
		if (colUpperLeft < startPosition + stopPosition)
		{
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
			colUpperLeft++;
		}
		else if (colUpperLeft == startPosition + stopPosition)
		{
			consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
			colUpperLeft = startPosition;
			consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
		}
	}
}

void Pea::hitZombie(Zombie* zombie)
{
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > MOVE_TIME))
	{
		begin = end;
		consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
		if (zombie && ((colUpperLeft == zombie->getColUpperLeft())/* || (colUpperLeft + 1 == zombie->getColUpperLeft())*/) && rowUpperLeft == zombie->getRowUpperLeft())
		{
			Log::getInstance().write("Zombie Hit!");
			zombie->takeDamage(damage);
		}
		if (colUpperLeft < startPosition + stopPosition)
		{
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
			colUpperLeft++;
		}
		else if (colUpperLeft == startPosition + stopPosition)
		{
			consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
			colUpperLeft = startPosition;
			consoleOut(rowUpperLeft, colUpperLeft - 1) << " ";
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
		}
	}
}