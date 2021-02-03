#include "CClassicZombie.h"
#include <time.h>


CClassicZombie::CClassicZombie()
{
	
}
CClassicZombie::CClassicZombie(int level)
{
	this->health = 5;  //trebuie 25
	this->speed = 2;
	this->nume = "CZ";
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
void CClassicZombie::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->x, this->y) << nume;
}
CClassicZombie::~CClassicZombie()
{
}
void CClassicZombie::deletePos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->x, this->y) << " ";
	conOut(this->x, this->y+1) << " ";
}