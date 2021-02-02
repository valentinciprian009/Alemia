#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"


class Bullet
{

private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;
	
public:
	int x=0, y=0;
	Bullet() {
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	}
	void Draw(int x,int y);
	

};

