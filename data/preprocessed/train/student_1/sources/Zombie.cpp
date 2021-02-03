#include"Zombie.h"

void Zombie::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << " O";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "-|";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "/\\";
}

bool Zombie::move()
{
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > moveSpeed))
	{
		begin = end;
		consoleOut(rowUpperLeft + 0, colUpperLeft + 1) << "  ";
		consoleOut(rowUpperLeft + 1, colUpperLeft + 1) << "  ";
		consoleOut(rowUpperLeft + 2, colUpperLeft + 1) << "  ";
		if (colUpperLeft > stopPosition)
		{
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
			colUpperLeft--;
			return true;
		}
		else
		{
			setCoordsUpperLeft(rowUpperLeft, colUpperLeft);
			print();
			return false;
		}
	}
	return true;
}

bool Zombie::hit(int& plantHealth)
{
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > moveSpeed))
	{
		begin = end;
		plantHealth -= damage;
		if (plantHealth > 0)
			return true;
		else
			return false;
	}
	return true;
}

bool Zombie::die()
{
	if (health <= 0)
	{
		Log::getInstance().write("Zombie Dead!");
		consoleOut(getRowUpperLeft() + 0, getColUpperLeft()) << "   ";
		consoleOut(getRowUpperLeft() + 1, getColUpperLeft()) << "   ";
		consoleOut(getRowUpperLeft() + 2, getColUpperLeft()) << "   ";
		return true;
	}
	return false;
}