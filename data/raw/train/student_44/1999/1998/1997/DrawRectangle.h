#pragma once
#include "DrawableScene.h"
#include <math.h>
#include <iostream>

class DrawRectangle : public DrawableScene
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawRectangle();
	void draw(int row, int col);
	void draw_score(int row, int col);
	~DrawRectangle();
};

