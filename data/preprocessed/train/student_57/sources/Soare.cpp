#include "Soare.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <stdlib.h>
#include <time.h>

int Soare::getNrOfRes()
{
	return this->resourses;
}

void Soare::showRes(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0xEE);
	conOut(row, col) << "---";
	conOut(row+1, col) << "---";
	conOut(row + 2, col) << "---";
	SetConsoleTextAttribute(h, 7);
}

