#pragma once
#include"CLevel.h"

class CBullet
{


public:
	CBullet();
	virtual ~CBullet();
	virtual void Start_Bullet_Attack(int x, int y);
	virtual void Display_attack();
	
};

