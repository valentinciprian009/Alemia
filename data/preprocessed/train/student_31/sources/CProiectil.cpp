#include "CProiectil.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include "CActions.h"

using namespace std::chrono;

int CProiectil::speed = 100;

int CProiectil::get_damage()
{
	return this->damage;
}

int CProiectil::get_x()
{
	return this->x;
}

int CProiectil::get_y()
{
	return this->y;
}

void CProiectil::reload()
{
	this->x = this->x_plant;
}

void CProiectil::print_proiectil()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(this->y, this->x + 6, 160) << L"*";

	conOut(this->y, this->x + 4, 8) << L" ";

	this->x+=2;

	if (this->x> 125)
	{
		this->x = this->x_plant;
	}
}

void CProiectil::set_coord(int x, int y)
{
	if (this->x == 0 && this->y == 0)
	{
		this->x = x;
		this->y = y;
	}
	this->x_plant = x;
}

int CProiectil::get_speed()
{
	return speed;
}

CProiectil::CProiectil()
{
	this->x = 0;
	this->y = 0;

	this->damage = 20;

}

CProiectil::~CProiectil()
{
}
