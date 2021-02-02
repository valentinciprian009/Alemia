#pragma once
#include"COut.h"
#include "Entity.h"
#include "MouseHandler.h"
#include <list>
class Sun :
	public Entity
{	
	int& inGameCurrency;
	MouseHandler& localHandler = MouseHandler::getInstance();
public:
	Sun(int& inGameCurrency, char img1, int x1, int y1, int color1);
	~Sun()
	{
		//localHandler.releaseInstance();
		unBind();
	}
	void update() 
	{
		int input = localHandler.getProcessedInput();
		int mouseX = localHandler.getPosX();
		int mouseY = localHandler.getPosY();
		if (input == 0 && mouseX == getX() && mouseY == getY())
		{
			collect();
		}
		Draw();
	}
private:
	void collect()
	{
		ConsoleHandler& out = ConsoleHandler::getInstance();
		set_finish();
		out(getX(), getY()) << "  ";
		inGameCurrency += 25;
	}
	void unBind()
	{

		set_finish();
	}

};

