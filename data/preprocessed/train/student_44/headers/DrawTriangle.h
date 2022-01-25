#pragma once
#include "DrawableScene.h"
class DrawTriangle :
	public DrawableScene
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawTriangle();
	void draw(int row, int col);
	~DrawTriangle();
};

