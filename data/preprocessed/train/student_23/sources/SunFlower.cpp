#include "SunFlower.h"

void SunFlower::printInShop(int x, int y)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	cout << "60$";
	SetConsoleTextAttribute(color, 14);
	cout<<" ___    ";
	conOut(x + 1, y);
	cout << "  _/   \\_  ";
	conOut(x + 2, y);
	cout << " (_\\ _ /_) ";
	conOut(x + 3, y);
	cout << " (_/   \\_) ";
	conOut(x + 4, y);
	cout << "   \\___/   ";
	conOut(x + 5, y);
	SetConsoleTextAttribute(color, 7);
	cout << "_____|_____";
}

void SunFlower::printInCadran(int x, int y)
{
	y = y * 12;
	y++;
	x = x--;
	x = x * 6;
	x++;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	SetConsoleTextAttribute(color, 14);
	cout << "    ___    ";
	conOut(x + 1, y);
	cout << "  _/   \\_  ";
	conOut(x + 2, y);
	cout << " (_\\ _ /_) ";
	conOut(x + 3, y);
	cout << " (_/   \\_) ";
	conOut(x + 4, y);
	cout << "   \\___/   ";
	conOut(x + 5, y);
	SetConsoleTextAttribute(color, 7);
	cout << "_____|_____";
}

bool SunFlower::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}
