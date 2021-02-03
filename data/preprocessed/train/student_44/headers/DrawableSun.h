#pragma once
#include "DrawableCharacter.h"

class DrawableSun :
	public DrawableCharacter
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawableSun();
	void draw(int row, int col);
	void getSun(int row, int col);
	~DrawableSun();
};

