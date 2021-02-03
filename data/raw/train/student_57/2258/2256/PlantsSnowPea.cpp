#include "PlantsSnowPea.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

void PlantsSnowPea::showPlat(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x11);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col) << this->cost;
}

void PlantsSnowPea::showPlatB(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x11);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
}

int PlantsSnowPea::getCost()
{
	return this->cost;
}

int PlantsSnowPea::getNrMuscaturi()
{
	return this->nr_muscaturi;
}

int PlantsSnowPea::getRegenerare()
{
	return this->regenerare;
}
