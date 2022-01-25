#pragma once
#include "PoleVaultingZombie.h"
#include "BucketHeadZombie.h"

class SuperZombie :
	public PoleVaultingZombie , public BucketHeadZombie
{
public:
	void draw(int x, int y);
	std::string identity();
	void useSkill();
	GameObject* clone();
};

