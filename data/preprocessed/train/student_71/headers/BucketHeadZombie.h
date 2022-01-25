#pragma once
#include "Zombie.h"

class BucketHeadZombie :
	virtual public Zombie
{
public:
	BucketHeadZombie();
	void draw(int x, int y);
	std::string identity();
	void useSkill();
	GameObject* clone();

};

