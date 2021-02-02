#pragma once
#include <direct.h>
#include"UserInterface.h"

class Menu
{
protected:
	UserInterface::ConsoleInput& consoleIn;
	UserInterface::ConsoleOutput& consoleOut;
public:
	Menu() : consoleIn(UserInterface::ConsoleInput::getInstance()), consoleOut(UserInterface::ConsoleOutput::getInstance()) { ; }
	UserInterface::ConsoleInput& consoleInput() const { return consoleIn; }
	UserInterface::ConsoleOutput& consoleOutput() const { return consoleOut; }
};