#pragma once
#include "CProiectil.h"
#define CHR_BULLET 248

class CPea :public CProiectil
{
public:
	CPea(int row, int col);
	~CPea();

	bool move() override;
};

