#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)
#include "iPlant.h"
class iPlantShooter :
	public virtual iPlant
{
public:
	virtual ~iPlantShooter() = 0 {};
	virtual int getAttackFrequency() const = 0;
	virtual void print() const = 0;
	virtual void action() = 0;
};

#pragma warning (pop)