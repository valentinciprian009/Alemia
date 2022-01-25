#pragma once
#include"LifeForm.h"
class Zombie:public LifeForm
{
private:

public:
	Zombie() {
		viata = 100;
		damage = 10;
		range = 2;
		icon = "Zz";
	}
	~Zombie() {}
};

