#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Game.h"

int main(void)
{
	try 
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		Game* instance = Game::getInstance();
		Game::run();
		conOut.clearScreen();
		Game::destroyInstance();
		conOut(39, 80) << "Press any key to exit";
	}
	catch (MyException & e)
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		conOut(39, 80) << e.what();
		Sleep(1000);
	}
	catch (std::exception & e)
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		conOut(39, 80) << e.what();
		Sleep(1000);
	}
	_getch();
	return 0;
}

