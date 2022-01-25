#pragma once
#include<iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "flower.h"

class Flower_tile
{

private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;
	Flower *fl;
public:
	int x=0, y=0;
	const static int width=5, height=4;



public:
	Flower_tile(int type)
	{	
		fl = new Flower(type);

		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	};

	Flower_tile& operator=(Flower_tile& ft) 
	{ return ft; 
	}

	void Draw(int x, int y);

	bool isClicked(COORD coord);

};

