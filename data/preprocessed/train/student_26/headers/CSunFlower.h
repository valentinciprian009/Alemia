#pragma once
#include "CPlants.h"
class CSunFlower:
	public CPlants
{
	int x;
	int y;
public:
	void deletepos();
	CSunFlower(int, int);
	CSunFlower();
	~CSunFlower();
};

