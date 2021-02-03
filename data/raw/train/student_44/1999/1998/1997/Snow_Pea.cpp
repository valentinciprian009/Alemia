#include "Snow_Pea.h"
#include "ConsoleOutput.h"

void Snow_Pea::draw(int col, int row)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << "\\Q~/";
}

void Snow_Pea::deleteDraw(int col, int row)

{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row,col) << "  ";
}


Snow_Pea::~Snow_Pea()
{
}
