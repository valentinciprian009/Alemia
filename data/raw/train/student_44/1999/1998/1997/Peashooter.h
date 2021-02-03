#pragma once
#include "Plant.h"
class Peashooter :
	public Plant
{
	
public:
	Peashooter() : Plant("Peashooter", PEASHOOTER, 20, 3, 2) {}

	void draw(int row, int col);
	void deleteDraw(int row, int col);

	~Peashooter();
};

