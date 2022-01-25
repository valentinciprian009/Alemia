#pragma once
#include "entity.h"
class Zombie :
	public entity
{
protected:
	int viata;
public:
	Zombie();
	virtual void pune_zombie() = 0;
	~Zombie();
};

