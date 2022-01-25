#pragma once
#pragma once
#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)
#include "Zombie.h"

class BucketHeadZombie :
	public virtual Zombie
{
public:
	void print() const override;
	void action() override;
	BucketHeadZombie(int x, int y, int health, int step);
	~BucketHeadZombie();
};

#pragma warning (pop)
