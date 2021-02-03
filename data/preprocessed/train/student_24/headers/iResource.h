#pragma once
#include "iEntity.h"
class iResource :
	public virtual iEntity
{
public:
	virtual void print() const override = 0;
	virtual ~iResource() = 0 {}
	virtual int getValue() const = 0;
};

