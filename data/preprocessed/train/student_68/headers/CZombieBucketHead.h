#pragma once
#include "CZombie.h"
class CZombieBucketHead :
	public CZombie
{
	int Health_;
	int Speed_;
public:
	CZombieBucketHead(int health, int speed) :CZombie() { this->Health_ = health; this->Speed_ = speed;
	CLog::getInstance().printLog("S-a apelat constructorul clasei CZombie_Super\n");
	};
	virtual ~CZombieBucketHead();
	void Display(string type_Zombie, int x, float y, CLevel& level) override;
};

