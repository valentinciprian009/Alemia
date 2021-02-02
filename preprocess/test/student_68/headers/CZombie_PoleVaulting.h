#pragma once
#include "CZombie.h"

#include"CBullet_FrozenPea.h"
#include"CBullet_Pea.h"



class CZombie_PoleVaulting :
	public CZombie
{
	int Health_;
	int Speed_;
public:
	CZombie_PoleVaulting(int health, int speed) : CZombie() { this->Health_ = health; this->Speed_ = speed; 
	CLog::getInstance().printLog("S-a apelat constructorul clasei CZombie_PoleVaulting\n");
	};
	virtual ~CZombie_PoleVaulting();
	void Display(string type_Zombie, int x, float y, CLevel& level);

};

