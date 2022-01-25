#include "Pea.h"
#include "ConsoleOutput.h"


Pea::Pea()
{
	power = 50;
}


void Pea::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "O";
}

Pea::~Pea()
{
}
