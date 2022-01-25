#include "Peashooter.h"
#include "ConsoleOutput.h"

void Peashooter::draw(int row, int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(col, row) << "\\Q/";
}

void Peashooter::deleteDraw(int row, int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(col, row) << "  ";
}

Peashooter::~Peashooter()
{
}
