#include "WallNut.h"

void WallNut::printInShop(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 12);
	conOut(x, y);
	cout << "   wWWWw   ";
	conOut(x + 1, y);
	cout << "   (___)   ";
	conOut(x + 2, y);
	cout << "     Y     ";
	SetConsoleTextAttribute(color, 7);
	conOut(x + 3, y);
	cout << "    \\|/ 40$";
	conOut(x + 4, y);
	cout << "   \\\\|//   ";
	conOut(x + 5, y);
	cout << "__\\\\\\|///__";
}

void WallNut::printInCadran(int x, int y)
{
	y = y * 12;
	y++;
	x = x--;
	x = x * 6;
	x++;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 12);
	conOut(x, y);
	cout << "   wWWWw   ";
	conOut(x + 1, y);
	cout << "   (___)   ";
	conOut(x + 2, y);
	cout << "     Y     ";
	SetConsoleTextAttribute(color, 7);
	conOut(x + 3, y);
	cout << "    \\|/    ";
	conOut(x + 4, y);
	cout << "   \\\\|//   ";
	conOut(x + 5, y);
	cout << "__\\\\\\|///__";
}

bool WallNut::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}