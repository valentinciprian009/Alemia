#include "CherryBomb.h"

void CherryBomb::printInShop(int x, int y)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	cout << "80$";
	conOut(x + 1, y);
	cout << "    \\      ";
	conOut(x + 2, y);
	cout << "     |     ";
	conOut(x + 3, y);
	cout << "    / \\    ";
	conOut(x + 4, y);
	SetConsoleTextAttribute(color, 4);
	cout << "  (_) (_)  ";
	SetConsoleTextAttribute(color, 7);
}

void CherryBomb::printInCadran(int x, int y)
{
	y = y * 12;
	y++;
	x = x--;
	x = x * 6;
	x++;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x + 1, y);
	cout << "    \\    ";
	conOut(x + 2, y);
	cout << "     |     ";
	conOut(x + 3, y);
	cout << "    / \\    ";
	conOut(x + 4, y);
	SetConsoleTextAttribute(color, 4);
	cout << "  (_) (_)  ";
	SetConsoleTextAttribute(color, 7);
}

bool CherryBomb::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}
