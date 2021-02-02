#include "Entity.h"

Entity::Entity(int x, int y) : coordX(x), coordY(y) {}

Entity::~Entity()
{
	colors.clear();
}

int Entity::getX() const
{
	return this->coordX;
}

int Entity::getY() const
{
	return this->coordY;
}

void Entity::setX(int x)
{
	coordX = x;
}

void Entity::setY(int y)
{
	coordY = y;
}

Entity& Entity::operator()(int x, int y)
{
	coordX = x;
	coordY = y;

	return *this;
}
