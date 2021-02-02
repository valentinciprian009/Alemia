#pragma once
#include "DrawableCharacter.h"
class DrawablePlant :
	public DrawableCharacter
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawablePlant();
	void draw(int row, int col) ;
	//void deleteDraw(int row, int col);
	~DrawablePlant();
};

