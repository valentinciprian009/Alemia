#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"

class Zombie
{
private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

public:
	int x, y;
	int life = 3;
	static const int width=3, height=2;
	bool is_active = false;
	Zombie()
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	};
	void Draw(int x,int y);
	void Clear();
	void Clear(int x, int y);

};

