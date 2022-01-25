#include "CZombie.h"



CZombie::CZombie(int row, int col) : CObject(row, col)
{
	CH = CHR_ZOMBIE;
	damage = 5;
	HP = 30;
	speed = 5;
	stop = false;
}

bool CZombie::move()
{
	if (stop)
		return false;
	if (bucle < speed)
	{
		bucle++;
		return false;
	}
	else
	{
		bucle = 0;
		this->x -= 5;
		return true;
	}
}

void CZombie::lowerHP(int d)
{
	this->HP -= d;
	if (this->HP < 0)
		this->HP = 0;
}

int CZombie::getDamage()
{
	return damage;
}

int CZombie::getHP()
{
	return HP;
}

void CZombie::setStop(bool b)
{
	stop = b;
}


CZombie::~CZombie()
{
}
