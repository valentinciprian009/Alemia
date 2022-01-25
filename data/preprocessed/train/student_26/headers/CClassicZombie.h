#pragma once
#include "CZombie.h"
class CClassicZombie:
	public CZombie
{

public:
	void draw();
	void deletePos();
	CClassicZombie();
	CClassicZombie(int);
	~CClassicZombie();
};

