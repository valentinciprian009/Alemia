#include "PlantsWallNut.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

void PlantsWallNut::showPlat(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x55);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col) << this->cost;
}

void PlantsWallNut::showPlatB(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x55);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
}

int PlantsWallNut::getCost()
{
	return this->cost;
}

int PlantsWallNut::getNrMuscaturi()
{
	return this->nr_muscaturi;
}

int PlantsWallNut::getRegenerare()
{
	return this->regenerare;
}