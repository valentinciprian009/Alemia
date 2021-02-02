#pragma once
#include "ConsoleInput.h"
class GenericZombie
{
protected:
	int viata;
	int viteza;
public:
	virtual void moveLeft() = 0;
	GenericZombie(int viata, int viteza);
	virtual void depleteLife(int amount) = 0;
};

