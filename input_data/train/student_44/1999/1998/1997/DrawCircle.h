#pragma once
#include "DrawableScene.h"
#include <math.h>
#include <iostream>


class DrawCircle :
	public DrawableScene
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawCircle();

	void draw(int row, int col);
	~DrawCircle();
};

