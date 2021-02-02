#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)
#include "iBattleEntity.h"
#include "iMovingEntity.h"

class iZombie
	: public virtual iBattleEntity, public virtual iMovingEntity
{
public:
	void print() const override = 0;
	virtual ~iZombie() = 0 {}
	virtual void action() = 0;
};

#pragma warning (pop)
