#include "CPeaShooter.h"
#include "CProiectil.h"
#include "CPea.h"

int CPeaShooter::cost = 100;
int CPeaShooter::timpUltimaAparitie = 0;


CPeaShooter::CPeaShooter(int row, int col):CPlanta(row,col)
{
	this->CH = 'P';
	this->HP = 15;
}


CPeaShooter::~CPeaShooter()
{
}

CProiectil * CPeaShooter::impusca()
{
	if (nrbucle == shootRate)
	{
		nrbucle = 0;
		return new CPea(this->y, this->x + 5);
	}
	else
	{
		nrbucle++;
		return nullptr;
	}
}
