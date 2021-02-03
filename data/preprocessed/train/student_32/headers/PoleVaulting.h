#pragma once
#include "Zombie.h"
class PoleVaulting :
	public Zombie
{
public:
	PoleVaulting(string name, int row, int col, int health, int damage, int speed) :Zombie(name, row, col, health, damage, speed) {};
};

