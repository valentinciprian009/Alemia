#include "ZombieDispenser.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "GameManager.h"

Arena::ZombieDispenser::ZombieDispenser(GameManager* pr, int lvl) 
	: ITickable(ZOMBIEINT), parent(pr)
{
	reset(lvl);
	/*
	std::string filename = "lvl";
	filename += lvl;
	filename += ".txt";
	std::ifstream fin(filename);
	//*/
}

void Arena::ZombieDispenser::reset(int lvl)
{
	resetTime();
	level = lvl;
	left = 10;
}

bool Arena::ZombieDispenser::done()
{
	return left == 0;
}

void Arena::ZombieDispenser::update()
{
	updateTime();
}

void Arena::ZombieDispenser::tickAction()
{
	if (left == 0)
		return;
	left--;
	int r = rand() % 100, y = rand() % parent->terenY();
	if (r > 85)
		parent->addZombie(2, y);
	else if (r > 60)
		parent->addZombie(1, y);
	else
		parent->addZombie(0, y);
}
