#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iEntity.h"

class iBattleEntity :
	public virtual iEntity
{
public:
	virtual ~iBattleEntity() = 0 {}
	virtual void print() const = 0;
	virtual void action() = 0;
	virtual int getHealth() const = 0;
	virtual void setHealth(const int& newHealth) = 0;
};
#pragma warning(pop)
