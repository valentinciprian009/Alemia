#include "Scoreboard.h"


Scoreboard::Scoreboard()
{
	//Square::DoASquare(0, 0);
}


Scoreboard::~Scoreboard()
{
}

void Scoreboard::PrintInteriorValue()
{
	DoASquare();
	Square::PrintInteriorValue(points);
}



