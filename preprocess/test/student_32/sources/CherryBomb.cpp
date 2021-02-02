#include "CherryBomb.h"



CherryBomb::CherryBomb(string name, int dmg, int row, int col, int health, int price)
{
	this->name = name;
	this->dmg = dmg;
	this->row = row;
	this->col = col;
	this->health = health;
	this->price = price;
}

void CherryBomb::set_col(int x)
{
	this->col = x;
}

void CherryBomb::set_row(int x)
{
	this->row = x;
}

int CherryBomb::get_price()
{
	return this->price;
}

int CherryBomb::get_health()
{
	return this->health;
}

int CherryBomb::get_col()
{
	return this->col;
}

int CherryBomb::get_row()
{
	return this->row;
}

string CherryBomb::get_name()
{
	return this->name;
}

bool CherryBomb::delay()
{
	return false;
}

void CherryBomb::take_damage(int dmg)
{
	this->health = this->health - dmg;
}
