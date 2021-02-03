#include "Proiectile.h"

void Proiectile::printTheProiectile(int colour)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, colour);
	cout << char(this->theProiectile);
	SetConsoleTextAttribute(color, 7);
}

void Proiectile::moveProiectile(int colour)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	y += 4;
	cout << " ";
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	conOut(x, y);
	if (y < 141)
	{
		SetConsoleTextAttribute(color, colour);
		cout << char(this->theProiectile);
		SetConsoleTextAttribute(color, 7);
	}
}

bool Proiectile::testTime(int time)
{
	auto shotTime = steady_clock::now();
	if (duration_cast<milliseconds>(shotTime - printedTime).count() > time)
	{
		printedTime = shotTime;
		return true;
	}
	return false;
}