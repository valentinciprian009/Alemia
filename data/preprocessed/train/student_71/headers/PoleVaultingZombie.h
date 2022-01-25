#pragma once
#include "Zombie.h"
class PoleVaultingZombie :
	virtual public Zombie
{
protected:
	bool jumped = false;
public:
	PoleVaultingZombie();
	void draw(int x, int y);
	std::string identity();
	void useSkill();
	GameObject* clone();
};

