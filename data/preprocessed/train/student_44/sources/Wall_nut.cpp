#include "Wall_nut.h"
#include "ConsoleOutput.h"

void Wall_nut::draw(int col, int row)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << "|W|";
}

Wall_nut::~Wall_nut()
{
}
