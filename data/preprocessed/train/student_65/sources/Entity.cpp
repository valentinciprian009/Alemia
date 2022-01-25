#include "Entity.h"
Entity::Entity()
{
	this->name = "";
	this->x = 0;
	this->y = 0;
}

Entity::Entity(const Entity& ent)
{
	this->x = ent.x;
	this->y = ent.y;
	this->name = ent.name;
}

void Entity::draw()
{
}

void Entity::update(std::string)
{
}

void Entity::set_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Entity::get_x()
{
	return x;
}

std::string Entity::get_name()
{
	return std::string(name);
}

int Entity::get_y()
{
	return y;
}

Entity::~Entity()
{
}

