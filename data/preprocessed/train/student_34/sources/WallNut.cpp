#include "WallNut.h"
#include <Windows.h>
#include "ConsoleOutput.h"


WallNut::WallNut()
{
}


void WallNut::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	conOut(x, y)     << "/ \\";
	conOut(x + 1, y) << "---";
	conOut(x + 2, y) << "\\ /";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

WallNut::~WallNut()
{
}
