#pragma once
#include "CObject.h"
#include "CMove.h"

class CProiectil :public CObject, public CMove
{
protected:
	int damage;

public:
	CProiectil(int row, int col);

	int getDamage();


	virtual ~CProiectil();
};

