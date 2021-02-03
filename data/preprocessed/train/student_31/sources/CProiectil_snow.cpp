#include "CProiectil_snow.h"
#include "ConsoleOutput.h"

int CProiectil_snow::speed = 100;


void CProiectil_snow::reload()
{
	this->x = this->x_plant;
}

int CProiectil_snow::get_damage()
{
	return this->damage;
}

void CProiectil_snow::print_proiectil()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(this->y, this->x + 6, 144) << L"*";
		
	conOut(this->y, this->x + 4, 8) << L" ";
	
	this->x += 2;

	if (this->x > 125)
	{
		this->x = this->x_plant;
	}
}

int CProiectil_snow::get_speed()
{
	return speed;
}

CProiectil_snow::CProiectil_snow(int x, int y)
{
	this->x = x;
	this->y = y;
	this->speed = 500;
	this->speed_invers_zombie = 500;
	this->damage = 25;
}

CProiectil_snow::CProiectil_snow()
{
	
	this->speed_invers_zombie = 500;
	this->damage = 20;
}

CProiectil_snow::~CProiectil_snow()
{
}
