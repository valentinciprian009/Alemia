#include "BucketHeadZ.h"

BucketHeadZ::~BucketHeadZ()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << "           ";
	conOut(x + 2, y);
	cout << "           ";
	conOut(x + 3, y);
	cout << "           ";
	conOut(x + 4, y);
	cout << "           ";
}

void BucketHeadZ::print()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << " /Bucket\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " xxx  xxx |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void BucketHeadZ::move()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << "           ";
	conOut(x + 2, y);
	cout << "           ";
	conOut(x + 3, y);
	cout << "           ";
	conOut(x + 4, y);
	cout << "           ";
	conOut(x + 5, y);
	cout << "           ";
	y = y - 12;
	conOut(x, y);
	conOut(x + 1, y);
	cout << " /Bucket\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " xxx  xxx |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void BucketHeadZ::spaceIt()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << "           ";
	conOut(x + 2, y);
	cout << "           ";
	conOut(x + 3, y);
	cout << "           ";
	conOut(x + 4, y);
	cout << "           ";
	conOut(x + 5, y);
	cout << "           ";
}
