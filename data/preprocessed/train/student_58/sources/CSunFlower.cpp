#include "CSunFlower.h"
#include "CProiectil.h"

int CSunFlower::cost = 50;
int CSunFlower::timpUltimaAparitie = 0;


CSunFlower::CSunFlower(int row, int col):CPlanta(row, col)
{
	this->CH = 'f';
	this->HP = 10;
}


CSunFlower::~CSunFlower()
{
}

CProiectil * CSunFlower::impusca()
{
	return nullptr;
}
