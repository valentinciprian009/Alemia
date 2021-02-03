#pragma once
#include "CPlanta.h"
class CPeaShooter :public CPlanta
{
public:
	CPeaShooter(int row, int col);
	~CPeaShooter();

	static int cost;
	static int timpUltimaAparitie;

	CProiectil* impusca() override;
};

