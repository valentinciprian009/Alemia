#include "Zombie.h"



Zombie::Zombie(Strategy * strategy, int health, int damage)
{
	this->strategy = strategy;
	this->health = health;
	this->damage = damage;
}

Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}
