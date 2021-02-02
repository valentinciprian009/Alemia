#include "SunflowerPlant.h"
#include "GameManager.h"

Arena::SunflowerPlant::SunflowerPlant(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x)
	: BasicPlant(pr, conout, 1, y, x)
{
	parent->addToRate(1);
}

Arena::SunflowerPlant::~SunflowerPlant()
{
	parent->addToRate(-1);
}

void Arena::SunflowerPlant::update()
{}
