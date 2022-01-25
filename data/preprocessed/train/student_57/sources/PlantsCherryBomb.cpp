#include "PlantsCherryBomb.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

void PlantsCherryBomb::showPlat(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x44);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col) << this->cost;
}

void PlantsCherryBomb::showPlatB(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x44);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
}

int PlantsCherryBomb::getCost()
{
	return this->cost;
}

int PlantsCherryBomb::getNrMuscaturi()
{
	return this->nr_muscaturi;
}

int PlantsCherryBomb::getRegenerare()
{
	return this->regenerare;
}
