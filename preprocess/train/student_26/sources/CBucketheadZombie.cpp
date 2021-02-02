#include "CBucketheadZombie.h"
#include <time.h>


CBucketheadZombie::CBucketheadZombie()
{
	
}
CBucketheadZombie::CBucketheadZombie(int level)
{
	this->health = 35;
	this->nume = "BZ";
	this->speed = 2;
	srand(time(NULL));
	int randLine = rand() % (2 * level - 1);
	if (level == 1)
	{
		randLine = 2;
	}
	if (level == 2)
	{
		while ((randLine == 0) || (randLine == 4))
			randLine = rand() % (2 * level - 1);
	}
	int y = 95;
	int x = 8 + randLine * 5;
	this->x = x;
	this->y = y;
}
void CBucketheadZombie::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->x, this->y) << nume;
}

void CBucketheadZombie::deletePos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->x, this->y) << " ";
	conOut(this->x, this->y + 1) << " ";
}

CBucketheadZombie::~CBucketheadZombie()
{
}
