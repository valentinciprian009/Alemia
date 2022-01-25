#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"

#include "bullet.h"
class Flower
{

private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;
	


public:
	int x, y;
	int type; // 1 - > 5
	int life;
	int price;
	Bullet bullet;


	Flower(int t):type(t){
		price = type * 5;
		life = type + 3;
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	};

	void Draw(int x, int y);

	int getPrice() { return price; };

	Flower&  operator=(Flower & flo){ return flo; };



};

