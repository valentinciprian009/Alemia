#include "PlantsSunFlower.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

void PlantsSunFlower::showPlat(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x66);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col) << this->cost;
}

void PlantsSunFlower::showPlatB(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x66);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
}

int PlantsSunFlower::getCost()
{
	return this->cost;
}

int PlantsSunFlower::getNrMuscaturi()
{
	return this->nr_muscaturi;
}

int PlantsSunFlower::getRegenerare()
{
	return this->regenerare;
}
