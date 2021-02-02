#include "CPlanta.h"



CPlanta::CPlanta(int row, int col):CObject(row,col)
{
	this->shootRate = 6;
}


CPlanta::~CPlanta()
{
}


void CPlanta::lowerHP(int d)
{
	this->HP -= d;
	if (this->HP < 0)
		this->HP = 0;
}

int CPlanta::getHP()
{
	return HP;
}