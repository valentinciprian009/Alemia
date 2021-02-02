#pragma once
#include "IShoot.h"
class CShoot :
	public IShoot
{
protected:
	int shootRate;
	int nrbucle;
public:
	CShoot();
	virtual ~CShoot();
};

