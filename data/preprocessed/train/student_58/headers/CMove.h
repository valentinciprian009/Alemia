#pragma once
#include "IMove.h"
class CMove :
	public IMove
{
protected:
	int speed;
	int bucle;

public:
	CMove();
	virtual ~CMove();
};

