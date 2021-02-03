#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iBattleEntity.h"
class iPlant :
	public virtual iBattleEntity
{
public:
	virtual ~iPlant() = 0 {}
	virtual void print() const override = 0;
	virtual void action() = 0;
	virtual int getPrice() const = 0;
	virtual iPlant* clone() = 0; //"virtual" copy constructor
};
#pragma warning(pop)
