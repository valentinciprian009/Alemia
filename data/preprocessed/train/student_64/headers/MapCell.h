#pragma once
#include "Square.h"
class MapCell
{
	Square square;
public:
	MapCell();
	~MapCell();

	MapCell(Square sq) { square = sq; }
	void setSquare(Square sq) { square = sq; }
	Square getSquare() { return square; }

};

