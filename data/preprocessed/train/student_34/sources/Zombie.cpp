#include "Zombie.h"
#include "ConsoleOutput.h"


Zombie::Zombie()
{
	health = 100;
}

void Zombie::draw(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "O";
	conOut(x + 1, y) << "/\\";
	conOut(x + 2, y) << "/\\";
}

void Zombie::delete_(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y-1) << "   ";
	conOut(x + 1, y) << "   ";
	conOut(x + 2, y) << "   ";
}


Zombie::~Zombie()
{
}
