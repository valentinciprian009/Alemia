#include "Wallnut.h"
#include "ConsoleOutput.h"

Wallnut::Wallnut()
{
	setPrice(50);
	setStrength(20);
}

void Wallnut::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * x, 20 + 15 * y + 6, 96) << L"▀▀▀▀";
	conOut(11 + 6 * x, 20 + 15 * y + 5, 96) << L" ●  ● ";
	conOut(12 + 6 * x, 20 + 15 * y + 5, 96) << L"   ◦  ";
	conOut(13 + 6 * x, 20 + 15 * y + 6, 96) << "    ";
	setX(x);
	setY(y);
}

void Wallnut::draw(int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * y, 8, 96) << L"▀▀▀▀";
	conOut(11 + 6 * y, 7, 96) << L" ●  ● ";
	conOut(12 + 6 * y, 7, 96) << L"   ◦  ";
	conOut(13 + 6 * y, 8, 96) << "    ";
}

std::string Wallnut::identity()
{
	return "Wallnut";
}
