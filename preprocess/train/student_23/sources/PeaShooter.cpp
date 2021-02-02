#include "PeaShooter.h"

void PeaShooter::printInShop(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	cout << "___________";
	conOut(x + 1, y);
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 13);
	cout << "   _(_)_   ";
	conOut(x + 2, y);
	cout << "  (_)@(_)  ";
	conOut(x + 3, y);
	SetConsoleTextAttribute(color, 7);
	cout << "   /";
	SetConsoleTextAttribute(color, 13);
	cout << "(_)    ";
	SetConsoleTextAttribute(color, 7);
	conOut(x + 4, y);
	cout << "   |   50 $";
	conOut(x + 5, y);
	cout << "   |/      ";
	conOut(x + 6, y);
	cout << "__\\|/_____";
}

void PeaShooter::printInCadran(int x, int y)
{
	y = y * 12;
	y++;
	x = x--;
	x = x * 6;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	cout << "___________";
	conOut(x + 1, y);
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 13);
	cout << "   _(_)_   ";
	conOut(x + 2, y);
	cout << "  (_)@(_)  ";
	conOut(x + 3, y);
	SetConsoleTextAttribute(color, 7);
	cout << "   /";
	SetConsoleTextAttribute(color, 13);
	cout << "(_)    ";
	SetConsoleTextAttribute(color, 7);
	conOut(x + 4, y);
	cout << "   |       ";
	conOut(x + 5, y);
	cout << "   |/      ";
	conOut(x + 6, y);
	cout << "__\\|/_____";
}

bool PeaShooter::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}
