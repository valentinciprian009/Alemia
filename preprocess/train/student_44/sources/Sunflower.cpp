#include "Sunflower.h"
#include "ConsoleOutput.h"

void Sunflower::draw(int col, int row)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << "~O~";
}

Sunflower::~Sunflower()
{
}
