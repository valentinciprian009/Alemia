#pragma once
#include "CPlants.h"
class CWallNut:
	public CPlants
{
	int x;
	int y;
public:
	void draw();
	void deletepos();
	CWallNut(int, int);
	CWallNut();
	~CWallNut();
};

