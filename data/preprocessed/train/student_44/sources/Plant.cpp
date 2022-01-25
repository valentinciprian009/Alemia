#include "Plant.h"
#include "BattleField.h"

Plant::Plant()
{
}

Plant::Plant(std:: string name, Tip_Planta tip, int price, int life, int timp ):Character(PLANT)
{
	this->name = name;
	this->type = tip;
	this->price = price;
	this->life = life;
	this->timp_crestere = timp;
}


void Plant::draw(int col, int row)
{
}

void Plant::actionare(BattleField * f)
{
}

Plant::~Plant()
{
}
