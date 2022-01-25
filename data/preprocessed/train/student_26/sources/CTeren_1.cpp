#include "CTeren_1.h"

void SetColorr(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void CTeren_1::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	SetColorr(4);
	for (int y = 16;y < 96 ;y++)
	{
		conOut(16,y) << "*";
		conOut(21,y) << "*";
	}
	SetColorr(7);
}

CTeren_1::CTeren_1()
{
	
}


CTeren_1::~CTeren_1()
{
}
