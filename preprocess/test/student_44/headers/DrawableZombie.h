#pragma once
#include "DrawableCharacter.h"
class DrawableZombie :
	public DrawableCharacter
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	DrawableZombie();

	void draw(int row, int col);
	void delete_draw(int row, int col);

	~DrawableZombie();
};

