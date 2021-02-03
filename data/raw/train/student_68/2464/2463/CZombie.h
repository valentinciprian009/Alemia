#pragma once
#include"CBullet_Pea.h"
#include"CBullet_FrozenPea.h"

class CZombie
{
protected:
	int pos_X; 
public:
	CZombie();
	virtual void Display(string type_Zombie, int x, float y, CLevel&level){}
	virtual ~CZombie();
	int GetPos_x();
};

