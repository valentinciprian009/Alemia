#pragma once
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"
class Super_Zombie :
	public BucketHead_Zombie, public PoleVaulting_Zombie
{

public:
	Super_Zombie();
	Super_Zombie(char forma, int atac, int viteza, int viata);
	~Super_Zombie();
};

