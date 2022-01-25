#pragma once
#include "Plant.h"
class Snow_Pea :
	public Plant
{
public:
	Snow_Pea() :Plant("Snow Pea", SNOW_PEA, 40, 3, 3) {}
	void draw(int col, int row);
	void deleteDraw(int col, int row);

	~Snow_Pea();
};

