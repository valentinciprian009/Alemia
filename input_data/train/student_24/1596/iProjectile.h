#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iMovingEntity.h"
#include "iBattleEntity.h"

class iProjectile :
	virtual public iMovingEntity
{
public:
	virtual ~iProjectile() = 0 {}
	virtual void print() const override = 0;
	virtual int getDamage() const = 0;
	virtual void hit(iBattleEntity& injured) = 0;
};
#pragma warning(pop)
