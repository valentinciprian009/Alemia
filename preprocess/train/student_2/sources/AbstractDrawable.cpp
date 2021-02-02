#include "AbstractDrawable.h"
void AbstractDrawable::setIndex(int index)
{
	this->index = index;
}

int AbstractDrawable::getIndex()
{
	return this->index;
}

int AbstractDrawable::getDrawnCol()
{
	return this->drawnAtCol;
}

int AbstractDrawable::getDrawnLine()
{
	return this->drawAtLine;
}

