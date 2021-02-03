#include "BlankSpace.h"

BlankSpace::BlankSpace(int centerLin, int centerCol)
{
	this->centerCol = centerCol;
	this->centerLin = centerLin;
}

void BlankSpace::draw(int line, int column)
{
}

std::string BlankSpace::getDrawableType()
{
	return this->type;
}

void BlankSpace::undraw()
{
}

int BlankSpace::getCenterCol()
{
	return this->centerCol;
}

int BlankSpace::getCenterLin()
{
	return centerLin;
}
