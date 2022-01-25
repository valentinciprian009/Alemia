#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)
#include "Zombie.h"

class SuperZombie :
	public virtual Zombie
{
private:
	int plantsEncountered;
public:
	void print() const override;
	void action() override;
	SuperZombie(int x, int y, int health, int step, int plantsEncountered);
	~SuperZombie() override;
};
#pragma warning(pop)
