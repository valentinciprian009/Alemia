#pragma once
#include "Zombie.h"
class ZombieBucketHead :
	virtual public Zombie
{
public:
	ZombieBucketHead(char img1, int x1, int y1, int color1, int dDmg, int tDmg, int hp);
	~ZombieBucketHead();
};

