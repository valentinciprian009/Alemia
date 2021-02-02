#include "Sunflower.h"

Sunflower::Sunflower(string name, int row, int col, int health, int price)
{
	this->row = row;
	this->col = col;
	this->health = health;
	this->price = price;
	this->name = name;
}

void Sunflower::set_col(int x)
{
	this->col = x;
}

void Sunflower::set_row(int x)
{
	this->row = x;
}

int Sunflower::get_price()
{
	return this->price;
}

int Sunflower::get_health()
{
	return this->health;
}

int Sunflower::get_col()
{
	return this->col;
}

int Sunflower::get_row()
{
	return this->row;
}

string Sunflower::get_name()
{
	return this->name;
}

bool Sunflower::delay()
{
	return false;
}

void Sunflower::take_damage(int dmg)
{
	this->health = this->health - dmg;
}
