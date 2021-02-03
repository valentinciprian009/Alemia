#include "CherryBomb.h"
#include "ConsoleOutput.h"
#include <Windows.h>


CherryBomb::CherryBomb()
{
}


void CherryBomb::draw(int x,int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	conOut(x  , y) << "  _";
	conOut(x+1, y) << " |";
	conOut(x+2, y) << "OO";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

}


CherryBomb::~CherryBomb()
{
}
