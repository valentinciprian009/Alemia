#include "PlantZone.h"



PlantZone::PlantZone()
{
}


PlantZone::~PlantZone()
{
}

void PlantZone::doAPlantZone()
{
	square.DoASquare();
	int x = square.getLeftCorner().get_x();
	int y = square.getLeftCorner().get_y();

	UserInterface::ConsoleOutput::getInstance()(y - 5, x + 5) << "&";

}
