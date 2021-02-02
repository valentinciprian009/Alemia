#pragma once
#include"User.h"
#include "ConsoleOutput.h"
class Menu
{
public:
	void PrintAnimation();
	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();
	User AskUserInput();
	Menu();
	~Menu();
};

