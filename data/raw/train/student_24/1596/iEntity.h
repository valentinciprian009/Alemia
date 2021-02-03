#pragma once
#include "iDrawable.h"
class iEntity :
	public iDrawable
{
public:
	virtual void print() const override = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
	virtual ~iEntity() = 0 {};
};

