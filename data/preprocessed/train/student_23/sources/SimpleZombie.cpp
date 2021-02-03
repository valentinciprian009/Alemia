#include "SimpleZombie.h"

SimpleZombie::~SimpleZombie()
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

void SimpleZombie::print()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << " /zombie\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " ===  === |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void SimpleZombie::move()
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
	cout << " /zombie\\  ";
	conOut(x + 2, y);
	cout << "/        \\ ";
	conOut(x + 3, y);
	cout << " ===  === |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void SimpleZombie::spaceIt()
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
