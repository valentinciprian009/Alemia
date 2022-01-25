#include "Sun.h"
#include <iostream>
#include <time.h>
#include "ConsoleOutput.h"
#include <windows.h>

using namespace std;

Sun::Sun()
{
	int n;
	this->x = 1;

	srand(time(NULL));
	n = rand() % 9 + 1;
	this->y = (n * 12) + 1;

	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 6);
	cout << "  \\     / ";
	conOut(x + 1, y);
	cout << "    .-.    ";
	conOut(x + 2, y);
	cout << "-- ( o ) --";
	conOut(x + 3, y);
	cout << "    '-'    ";
	conOut(x + 4, y);
	cout << "  /     \\ ";
	SetConsoleTextAttribute(color, 7);
}

Sun::~Sun()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	cout << "           ";
	conOut(x + 1, y);
	cout << "           ";
	conOut(x + 2, y);
	cout << "           ";
	conOut(x + 3, y);
	cout << "           ";
	conOut(x + 4, y);
	cout << "           ";
}