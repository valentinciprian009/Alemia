#include "Frozen_Pea.h"
#include "ConsoleOutput.h"
#include <Windows.h>


Frozen_Pea::Frozen_Pea()
{
}


void Frozen_Pea::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	conOut(x, y) << "O";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

Frozen_Pea::~Frozen_Pea()
{
}
