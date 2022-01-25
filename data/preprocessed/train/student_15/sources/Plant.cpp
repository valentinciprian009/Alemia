#include "Plant.h"
#include "Slide.h"
#include "GameManager.h"

using namespace Arena;

BasicPlant::BasicPlant(GameManager* pr, UserInterface::ConsoleOutput conout, int plantID, int y, int x) : IGameElement(pr, conout)
{
	this->y = y;
	this->x = x;
	id = plantID;
	if (id != -1)
		hp = BasicPlant::plants[id].maxHP;
	else
		hp = 0;
}

Arena::BasicPlant::~BasicPlant()
{
	if (id != -1)
	{
		Slide::clearZone(
			conOut,
			VLINE + 2 + x * CELLX,
			HLINE + 2 + y * CELLY,
			VLINE + (x+1) * CELLX,
			HLINE + (y+1) * CELLY
		);
		std::string s = "The ";
		s += plants[id].name;
		s += " at cell (";
		s += '0' + y + 1;
		s += ", ";
		s += '0' + x + 1;
		s += ") died.";
		parent->log(s);
	}
}

int Arena::BasicPlant::getID()
{
	return id;
}

void Arena::BasicPlant::damage()
{
	hp--;
}

bool Arena::BasicPlant::active()
{
	return hp>0;
}

void Arena::BasicPlant::draw()
{
	if (id == -1)
		return;
	Slide::drawAsciiArt(
		BasicPlant::plants[id].filename, 
		conOut,
		HLINE + 2 + y * CELLY,
		VLINE + 2 + x * CELLX
	);
}