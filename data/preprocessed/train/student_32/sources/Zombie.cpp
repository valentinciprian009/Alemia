#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::Zombie(string name, int row, int col, int health, int damage, int speed)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	this->name = name;
	this->row = row;
	this->col = col;
	this->health = health;
	this->damage = damage;
	this->speed = speed;
	this->jump = 0;
	conOut(row, col) << this->name;
}

int Zombie::get_col()
{
	return this->col;
}

int Zombie::get_row()
{
	return this->row;
}

int Zombie::get_health()
{
	return this->health;
}

int Zombie::get_damage()
{
	return this->damage;
}

int Zombie::get_speed()
{
	return this->speed;
}

string Zombie::get_name()
{
	return this->name;
}

bool Zombie::delay()
{
	auto time = steady_clock::now();
	if (duration_cast<milliseconds>(time - last_move).count() > this->speed)
	{
		last_move = time;
		return true;
	}
	return false;
}

void Zombie::move()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << " ";
	this->col--;
	if (this->col % 6 == 5)
	{
		this->col = this->col -1;
	}
	conOut(row, col) << this->name;
}

void Zombie::take_damage(int x)
{
	this->health = this->health - x;
}

void Zombie::set_row(int x)
{
	this->row = x;
}

void Zombie::set_col(int x)
{
	this->col = x;
}

void Zombie::set_jump()
{
	this->jump = 1;
}

int Zombie::get_jump()
{
	return this->jump;
}
