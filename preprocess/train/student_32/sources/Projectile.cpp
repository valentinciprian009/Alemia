#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::Projectile(int row, int col, int damage, int frequency)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	this->row = row;
	this->col = col+1;
	this->damage = damage;
	this->frequency = frequency;
	conOut(this->row, this->col) << "*";
}

void Projectile::tranform_col(int val)
{
	this->col = val;
}

int Projectile::get_col()
{
	return this->col;
}

int Projectile::get_row()
{
	return this->row;
}

int Projectile::get_frequency()
{
	return this->frequency;
}

int Projectile::get_damage()
{
	return this->damage;
}

void Projectile::move()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << " ";
	this->col++;
	if (this->col % 6 == 5)
	{
		this->col = this->col + 1;
	}
	if (this->col % 6 == 2)
	{
		this->col = this->col + 1;
	}
	conOut(row, col) << "*";
}

bool Projectile::delay()
{
	auto time = steady_clock::now();
	if (duration_cast<milliseconds>(time - lastshot).count() > this->frequency)
	{
		lastshot = time;
		return true;
	}
	return false;
}
