#include "SuperZombie.h"

SuperZombie::~SuperZombie()
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

void SuperZombie::print()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << " /SuperZ\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " sss  sss |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void SuperZombie::move()
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
	cout << " /SuperZ\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " sss  sss |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void SuperZombie::spaceIt()
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
