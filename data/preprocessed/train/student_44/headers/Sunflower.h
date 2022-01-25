#pragma once
#include "Plant.h"
class Sunflower :
	public Plant
{
public:
	Sunflower() : Plant("Sunflower", SUNFLOWER, 50, 3, 2) {}

	void draw(int col, int row);
	void deleteDraw(int col,int row)
	{
		UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
		conOut(row, col) << "  ";
	}

	~Sunflower();
};

