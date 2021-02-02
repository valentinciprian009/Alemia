#include "Plant.h"





Plant::Plant(int health, string type)
{
	this->health = health;
	this->type = type;
}

Plant::~Plant()
{
}

bool Plant::is_dead()
{
	return this->health <= 0;
}

void Plant::take_damage(int damage)
{
	this->health -= damage;
}
