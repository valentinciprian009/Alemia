#pragma once
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
class CIcons
{
protected:
	char icon[3];
	int cx, cy[3];
public:
	CIcons() {
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		icon[0] = 'P';
	}
};

