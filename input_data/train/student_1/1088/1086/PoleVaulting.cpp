#include"PoleVaulting.h"

void PoleVaulting::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << " ^";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "-|";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "/\\";
}