#include "FrozenPea.h"

void FrozenPea::printInShop(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 9);
	conOut(x, y);
	cout << "   _,-._   ";
	conOut(x + 1, y);
	cout << " /  \\_/  \\";
	conOut(x + 2, y);
	cout << " >--(_)--< ";
	conOut(x + 3, y);
	cout << " \\ _/ \\_ /";
	conOut(x + 4, y);
	cout << "    '-'    ";
	conOut(x + 5, y);
	SetConsoleTextAttribute(color, 7);
	cout << "____70 $___";
}

void FrozenPea::printInCadran(int x, int y)
{
	y = y * 12;
	y++;
	x = x * 6;
	x -= 5;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 9);
	conOut(x, y);
	cout << "   _,-._   ";
	conOut(x + 1, y);
	cout << " /  \\_/  \\";
	conOut(x + 2, y);
	cout << " >--(_)--< ";
	conOut(x + 3, y);
	cout << " \\ _/ \\_ /";
	conOut(x + 4, y);
	cout << "    '-'    ";
	SetConsoleTextAttribute(color, 7);
}

bool FrozenPea::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}
