#include "Peashooter.h"

Peashooter::Peashooter(string nume, int viata, int pret, int time, int rand, int coloana)
{
	this->name = nume;
	this->health = viata;
	this->price = pret;
	this->shootingTime = time;
	this->row = rand;
	this->col = coloana;
}

int Peashooter::get_health()
{
	return this->health;
}

int Peashooter::get_col()
{
	return this->col;
}

int Peashooter::get_row()
{
	return this->row;
}

int Peashooter::get_price()
{
	return this->price;
}

void Peashooter::set_col(int x)
{
	this->col = x;
}

void Peashooter::set_row(int y)
{
	this->row = y;
}

string Peashooter::get_name()
{
	return this->name;
}

bool Peashooter::delay()
{
	auto time = steady_clock::now();
	if (duration_cast<milliseconds>(time - lastShooting).count() > this->shootingTime)
	{
		lastShooting = time;
		return true;
	}
	return false;
}

void Peashooter::take_damage(int dmg)
{
	this->health = this->health - dmg;
}
