#include "Wallnut.h"

Wallnut::Wallnut(string nume, int viata,int pret, int rand, int coloana)
{
	this->name = nume;
	this->health = viata;
	this->row = rand;
	this->col = coloana;
	this->price = pret;
}


int Wallnut::get_health()
{
	return this->health;
}

int Wallnut::get_col()
{
	return this->col;
}

int Wallnut::get_row()
{
	return this->row;
}

int Wallnut::get_price()
{
	return this->price;
}

void Wallnut::set_col(int x)
{
	this->col = x;
}

void Wallnut::set_row(int y)
{
	this->row = y;
}

string Wallnut::get_name()
{
	return this->name;
}

bool Wallnut::delay()
{
	return true;
}

void Wallnut::take_damage(int dmg)
{
	this->health = this->health - dmg;
}
