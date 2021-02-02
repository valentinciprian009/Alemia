#include "Plant.h"

Plant::Plant(int x, int y, int health, int price) : BattleEntity(x, y, health), m_Price(price) {}


Plant::~Plant()
{
	this->colors.clear();
}

int Plant::getPrice() const
{
	return this->m_Price;
}
