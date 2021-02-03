#include "Sunflower.h"
#include "ConsoleOutput.h"
#include <Windows.h>


Sunflower::Sunflower()
{
}


void Sunflower::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	conOut(x  , y) << " ( )";
	conOut(x+1, y) << "(_X_)";
	conOut(x+2, y) << "  j";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

Sunflower::~Sunflower()
{
}
