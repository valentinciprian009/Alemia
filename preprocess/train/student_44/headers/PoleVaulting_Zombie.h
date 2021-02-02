#pragma once
#include "Zombie.h"
class PoleVaulting_Zombie :
	public Zombie
{

public:
	PoleVaulting_Zombie() : Zombie("PoleVaulting", PV_ZOMBIE,3){}

	void actionare(BattleField * f)
	{

	}

	~PoleVaulting_Zombie();
};

