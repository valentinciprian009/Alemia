#include "CPea.h"



CPea::CPea(int row, int col): CProiectil(row, col)
{
	this->CH = '*';
	this->damage = 10;
	this->speed = 3;
}


CPea::~CPea()
{
}

bool CPea::move()
{
	if (bucle < speed)
	{
		bucle++;
		return false;
	}
	else
	{
		bucle = 0;
		this->x += 5;
		return true;
	}
}
