#pragma once
#include"LifeForm.h"
class BucketZombie:public LifeForm
{
private:


public:
	BucketZombie() {
		viata = 150;
		damage = 15;
		range = 2;
		icon = "Bkz";
	}
	~BucketZombie() {}
};

