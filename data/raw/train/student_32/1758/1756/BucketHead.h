#pragma once
#include "Zombie.h"
class BucketHead :
	public Zombie
{
public:
	BucketHead(string name, int row, int col, int health, int damage, int speed) :Zombie(name, row, col, health, damage, speed) {};
};

