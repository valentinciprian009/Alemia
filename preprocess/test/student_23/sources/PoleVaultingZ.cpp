#include "PoleVaultingZ.h"

PoleVaultingZ::~PoleVaultingZ()
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

void PoleVaultingZ::print()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y);
	conOut(x + 1, y);
	cout << " / Pole \\  ";
	conOut(x + 2, y);
	cout << "/    Z   \\ ";
	conOut(x + 3, y);
	cout << " ~~~  ~~~ |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void PoleVaultingZ::move()
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
	cout << " / Pole \\  ";
	conOut(x + 2, y);
	cout << "/    Z   \\ ";
	conOut(x + 3, y);
	cout << " ~~~  ~~~ |";
	conOut(x + 4, y);
	cout << "\\   \\/   / ";
	conOut(x + 5, y);
	cout << " \\_VVVV_/  ";
}

void PoleVaultingZ::spaceIt()
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
