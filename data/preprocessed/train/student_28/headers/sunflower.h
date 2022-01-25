#pragma once
#include "sun.h"
#include "Plant.h"
class sunflower:public Plant,public sun
{public:
	friend sun;
	sunflower(int x ,int y);
	sunflower();
	sun* makesunflower(int x,int y);
	void afiseaza(COORD num);
};

