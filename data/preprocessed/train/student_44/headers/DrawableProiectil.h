#pragma once
#include "DrawableCharacter.h"
class DrawableProiectil :
	public DrawableCharacter
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawableProiectil();
	void draw(int row, int col);
	void deleteDraw(int row, int col) { conOut(row, col) << " "; }

	~DrawableProiectil();
};

