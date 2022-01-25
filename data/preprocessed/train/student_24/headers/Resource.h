#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)
#include "iResource.h"
#include "Entity.h"

class Resource
	:public virtual iResource, public virtual Entity
{
protected:
	int m_Value;

public:
	virtual void print() const = 0;
	virtual ~Resource() override;
	Resource(int x, int y, int val);
	int getValue() const override;
};

#pragma warning(pop)