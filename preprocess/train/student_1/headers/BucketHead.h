#pragma once
#include"Zombie.h"
#define MAX_HEALTH_BUCKETHEAD 1700

class BucketHead : virtual public Zombie
{
public:
	BucketHead() : Zombie() { ; }
	BucketHead(int row_ul, int col_ul, int ln, int stop) : Zombie(row_ul, col_ul, ln, MAX_HEALTH_BUCKETHEAD, DAMAGE, MOVE_SPEED_ZOMBIE, stop, 2) { ; }
	virtual void print();
	virtual bool checkJump() { return 0; }
	virtual void vault() { ; }
};