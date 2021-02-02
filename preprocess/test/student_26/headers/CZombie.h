#pragma once
#include "CEntity.h"
class CZombie:
	public CEntity
{
public:
	bool hit = false;
	int damage = 10;
	int x;
	int y;
	string nume;
	int health;
	int speed;
	virtual void draw()=0;
	void updatePos();
	virtual void deletePos();
	CZombie();
	
	~CZombie();
};

