#include "Cherry_Bomb.h"
#include "ConsoleOutput.h"

void Cherry_Bomb::draw(int col, int row)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(row,col) << "@";
}

void Cherry_Bomb::deleteDraw(int col, int row)
{
 UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance(); 
	conOut(row, col) << " ";
}

Cherry_Bomb::~Cherry_Bomb()
{
}
