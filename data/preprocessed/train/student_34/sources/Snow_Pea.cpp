#include "Snow_Pea.h"
#include <Windows.h>
#include "ConsoleOutput.h"

Snow_Pea::Snow_Pea()
{
}


void Snow_Pea::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	conOut(x, y) << char(239);
	conOut(x + 1, y) << char(219) << char(198);
	conOut(x + 2, y) << char(207);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

Snow_Pea::~Snow_Pea()
{
}
