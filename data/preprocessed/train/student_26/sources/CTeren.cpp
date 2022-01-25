#include "CTeren.h"

#include<vector>

void CTeren::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(0, 0) << "SCOREBOARD :" << "\n";

	char c = 219;
	int x;
	int y = 15;
	for (int k = 0; k < 9;k++)
	{
		for (x = 0;x < 6;x++)
		{
			conOut(x, y) << c;
		}
		y = y + 10;
	}
	for (int y = 6;y < 32;y++)
	{
		conOut(y, 15)<<c;
	}
	x = 6;
	for (int a = 0;a < 6;a++)
	{
		for (y = 0;y < 15;y++)
		{
			conOut(x, y) << c;
		}
		x = x + 5;
	}

	x = 6;
	y = 10;
	for (y = 0;y < 96;y++)
	{
		conOut(x, y) << c;
	}
	int x_beg = 25;
	int punct = 7;
	for (int k = 0;k < 5;k++)
	{
		for (int k1 = 0;k1 < 8;k1++)
		{
			for (int y_beg = punct;y_beg < punct + 4;y_beg++)
			{
				conOut(y_beg, x_beg) << " ";
			}
			x_beg = x_beg + 10;
		}
		punct = punct + 5;
		x_beg = 25;
	}	
}

CTeren::CTeren(int level)
{
	this->level = level;
}

CTeren::CTeren()
{
}


CTeren::~CTeren()
{
}
