#pragma once
#include "CObject.h"
#include "CShoot.h"
class CPlanta :public CObject, public CShoot
{
protected:
	int HP;

public:
	CPlanta(int row, int col);

	void lowerHP(int);
	int getHP();

	virtual ~CPlanta();
};

