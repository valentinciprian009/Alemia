#pragma once
#include "Zombie.h"
class BucketHead_Zombie :
	public Zombie
{

public:

	BucketHead_Zombie(): Zombie("BucketHead_Zombie",BH_ZOMBIE,6) { }

	~BucketHead_Zombie();
};

