#pragma once
#include "Zombie.h"
class SuperZombie :
	public Zombie
{
public:
	SuperZombie(string name, int row, int col, int health, int damage, int speed) :Zombie(name, row, col, health, damage, speed) {};
};

