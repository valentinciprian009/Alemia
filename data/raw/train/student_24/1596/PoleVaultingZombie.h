#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)
#include "Zombie.h"
class PoleVaultingZombie :
	public Zombie
{
private:
	int plantsEncountered;
public:
	void print() const override;
	void action() override;
	PoleVaultingZombie(int x, int y, int health, int step, int PlantsEncountered);
	~PoleVaultingZombie();
};

#pragma warning (pop)