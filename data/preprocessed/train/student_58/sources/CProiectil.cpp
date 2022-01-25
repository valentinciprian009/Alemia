#include "CProiectil.h"



CProiectil::CProiectil(int row, int col) : CObject(row, col)
{
}

int CProiectil::getDamage()
{
	return damage;
}


CProiectil::~CProiectil()
{
}
