#pragma once
#include "Plant.h"

class Wall_nut :
	public Plant
{
public:
	Wall_nut() :Plant("Wallnut", WALL_NUT, 30, 4, 4) {}

	void draw(int col, int row);
	void deleteDraw(int col, int row)
	{
			UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
			conOut(row, col) << "  ";
	}
	~Wall_nut();
};

