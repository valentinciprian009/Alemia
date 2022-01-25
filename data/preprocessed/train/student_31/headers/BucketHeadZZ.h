#pragma once
#include "CZombie.h"

class BucketHeadZZ:public CZombie
{

public:
	int move();
	void print_zombie(int x,int y);
	BucketHeadZZ();
	~BucketHeadZZ();
};

