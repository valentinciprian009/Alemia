#pragma once
#include "Plant.h"
class Cherry_Bomb :
	public Plant
{
public:
	Cherry_Bomb() : Plant("Cherry Bomb", CHERRY_BOMB, 30, 3, 3){}

	void draw(int col, int row);

	void deleteDraw(int col, int row);

	~Cherry_Bomb();
};

