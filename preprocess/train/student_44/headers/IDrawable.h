#pragma once
#include <iostream>
#include "ConsoleOutput.h"
class IDrawable
{
	
public:
	
	virtual void draw(int row,int col) = 0;
};

