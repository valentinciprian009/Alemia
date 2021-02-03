#pragma once
#include"BucketHead.h"
#include"PoleVaulting.h"
#define MAX_HEALTH_SUPERZOMBIE 1800
#define MOVE_SPEED_SUPERZOMBIE 150
#define DAMAGE_SUPERZOMBIE 20

class SuperZombie : public BucketHead, public PoleVaulting
{
public:
	SuperZombie() : BucketHead(), PoleVaulting() { setType(4); Log::getInstance().write("SuperZombie created"); }
	SuperZombie(int row_ul, int col_ul, int ln, int stop);
	void print();
	virtual bool checkJump() { return jump; }
	virtual void vault() { Log::getInstance().write("PoleVaulting Zombie jumped!"); jump = 0; }
};