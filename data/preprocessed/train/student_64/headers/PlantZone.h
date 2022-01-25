#pragma once
#include "Square.h"
#include "ConsoleOutput.h"
class PlantZone
{
	Square square;
public:
	PlantZone();
	~PlantZone();

	PlantZone(Square sq) { square = sq; }
	Square getSquare() { return square; }
	void setSquare(Square sq) { square = sq; }

	void doAPlantZone();

};

