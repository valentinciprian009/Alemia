#pragma once
#include "Zombie.h"
class Super_Zombie :
	public Zombie
{
public:
	Super_Zombie() : Zombie("Super Zombie", S_ZOMBIE,6) {}


	void actionare(BattleField * f)
	{

	}


	~Super_Zombie();
};

