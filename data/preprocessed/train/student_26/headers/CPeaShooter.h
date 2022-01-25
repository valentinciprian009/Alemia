#pragma once
#include "CPlants.h"
class CPeaShooter : public CPlants
{
public:
	int x;
	int y;
	void deletepos();
	void draw();
	CPeaShooter(int,int);
	CPeaShooter();
	~CPeaShooter();
};

