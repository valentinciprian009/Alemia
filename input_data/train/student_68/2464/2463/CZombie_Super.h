#pragma once
#include "CZombie.h"
class CZombie_Super :
	public CZombie
{
	int Health_;
	int Speed_;
	//int Appearance_;
public:
	CZombie_Super(int health, int speed) :CZombie() { this->Health_ = health; this->Speed_ = speed;  
	CLog::getInstance().printLog("S-a apelat constructorul clasei CZombie_Super\n");
	};
	virtual ~CZombie_Super();
	void Display(string type_Zombie, int x, float y, CLevel& level) override;
};

