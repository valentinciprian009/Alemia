#pragma once
#include "Zombie.h"
class NormalZombie :
	public Zombie
{
public:
	NormalZombie();
	void draw(int x, int y);
	std::string identity();
	void useSkill();
	GameObject* clone();

};

