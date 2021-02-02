#pragma once
#include "IDrawable.h"
class DrawableScene :
	public IDrawable
{
	//UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
public:
	//DrawableScene();
	virtual void draw(int row, int col)=0;
//	virtual ~DrawableScene();
};

