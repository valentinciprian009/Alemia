#pragma once
#include "Entity.h"
class Lifeform :
	public Entity
{
	int hp;
	bool _isDead;

public:
	Lifeform(char img1, int x1, int y1, int color1,int hp);
	~Lifeform();
	bool isDead()	{ return _isDead;}
	int getHp()		{return hp;}
};

