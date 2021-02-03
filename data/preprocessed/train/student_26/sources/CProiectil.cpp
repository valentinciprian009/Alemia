#include "CProiectil.h"

void CProiectil::updatePos()
{
	
	int oldX = this->x;
	int oldY = this->y;
 	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	this->y += this->speed;
	conOut(oldX, oldY) << ' ';
	conOut(this->x, this->y) << symbol;

	if (this->y >= 95)
	{
		deletePos();
		this->hit = 1;
	}
}

void CProiectil::deletePos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->x, this->y) << " ";
}

void CProiectil::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << symbol;
}

CProiectil::CProiectil(int x,int y)
{
	this->x = x;
	this->y = y;
}


CProiectil::~CProiectil()
{
}
