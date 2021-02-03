#pragma once
#include "CZombie.h"
class CZombie_Banal :
	public CZombie
{
	int Health_;
	int Speed_;
public:
	CZombie_Banal(int health, int speed) :CZombie()
	{
		this->Health_ = health;
		this->Speed_ = speed;
		CLog::getInstance().printLog("S-a apelat constructorul clasei CZombie_Banal\n");
	}
	virtual ~CZombie_Banal();
	void Display(string type_Zombie, int x, float y, CLevel& level) override;
};

