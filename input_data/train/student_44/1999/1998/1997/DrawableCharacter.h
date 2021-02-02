#pragma once
#include "IDrawable.h"
class DrawableCharacter :
	public IDrawable
{
public:
	//DrawableCharacter();
	virtual void draw(int row, int col) = 0;
	//virtual ~DrawableCharacter();
};

