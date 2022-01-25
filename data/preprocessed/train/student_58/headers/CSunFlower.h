#pragma once
#include "CPlanta.h"
class CSunFlower :public CPlanta
{

public:
	CSunFlower(int row, int col);
	~CSunFlower();

	static int cost;
	static int timpUltimaAparitie;
	
	CProiectil* impusca() override;
};

