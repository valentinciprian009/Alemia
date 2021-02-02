#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)

#include "BattleEntity.h"
#include "MovingEntity.h"
#include "iZombie.h"

class Zombie
	: public virtual iZombie, public virtual BattleEntity, public virtual movingEntity
{
public:
	virtual void print() const override;
	virtual void action() override;
	~Zombie() override;
	Zombie(int x, int y, int health, int step);
};
#pragma warning(pop)

