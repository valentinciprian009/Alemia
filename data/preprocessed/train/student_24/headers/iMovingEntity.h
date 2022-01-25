#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iEntity.h"
class iMovingEntity :
	virtual public iEntity
{
public:
	virtual ~iMovingEntity() = 0 {}
	void print() const override = 0;
	virtual int getStep() const = 0;
	virtual void move() = 0;
};
#pragma warning(pop)
