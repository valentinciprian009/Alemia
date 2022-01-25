#pragma once
#include"CObject.h"
#include"CMove.h"
#define CHR_ZOMBIE 35
#define CHR_BUCKETHEAD 36

class CZombie:public CObject, public CMove
{
protected:
	int HP;
	int damage;
	bool stop;

public:
	CZombie(int row,int col);

	bool move() override;
	void lowerHP(int);
	int getDamage();
	int getHP();
	void setStop(bool);

	~CZombie();
};

