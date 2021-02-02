#include "CZombie.h"
#include "ConsoleOutput.h"

#include <conio.h>
#include<chrono>
#include<time.h>

using namespace std::chrono;



void CZombie::set_free()
{
	this->free = 1;
}

void CZombie::reset_free()
{
	this->free = 0;
}

int CZombie::return_free()
{
	return this->free;
}

void CZombie::stay()
{
	this->x_coordz += 10;
}

void CZombie::go()
{
	this->x_coordz -= 10;
}

void CZombie::print_zombie(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	 conOut(y + 1, x, 8) << L"████";
	conOut(y + 2, x, 13) << L"  █";
	conOut(y + 3, x, 8) << L"█ ";
	conOut(y + 3, x + 2, 13) << L"█ ";
	conOut(y + 3, x + 4, 8) << L"█";
	conOut(y + 4, x, 8) << L" █ █";

	this->x_coordz = x;
	this->y_coordz = y;

}

void CZombie::delete_zobie(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(y + 1, x, 8) << L"    ";
	conOut(y + 2, x, 8) << L"   ";
	conOut(y + 3, x, 8) << L"     ";
	conOut(y + 4, x, 8) << L"    ";
}

int CZombie::minus_life(int val_minus)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	this->health = this->health - val_minus;

	if (this->health < 0)
	{
		return 0;
	}
	return 1;
}

int CZombie::get_health()
{
	return this->health;
}

int CZombie::get_speed()
{
	return speed;
}

int CZombie::x_z()
{
	return this->x_coordz;
}

int CZombie::y_z()
{
	return this->y_coordz+1;
}

int CZombie::move()
{
	
	this->delete_zobie(this->x_coordz, this->y_coordz);
	this->x_coordz = this->x_coordz - 10;
	this->print_zombie(this->x_coordz, this->y_coordz);

	if (this->x_coordz < 30)
		return 0;
	return 1;

}

CZombie::CZombie()
{
	this->health = 100;
	this->speed = 3000;
	this->free = 0;

}


CZombie::~CZombie()
{
}
