#include"ScoreTable.h"

void ScoreTable::updateInfo(int sc, int sunQty)
{
	ScoreBoard::updateInfo(sc, sunQty);
	consoleOut(rowUpperLeft + 4, colUpperLeft + 11) << "         ";
	consoleOut(rowUpperLeft + 5, colUpperLeft + 11) << "         ";
	print();
}

void ScoreTable::updateSunQuantity(int sunQty)
{
	ScoreBoard::updateSunQuantity(sunQty); 
	consoleOut(rowUpperLeft + 5, colUpperLeft + 11) << "         ";
	print(); 
}


void ScoreTable::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << "#######################";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "#";
	consoleOut(rowUpperLeft + 1, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "#   User:";
	consoleOut(rowUpperLeft + 2, colUpperLeft + 11) << username;
	consoleOut(rowUpperLeft + 2, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 3, colUpperLeft) << "#   Level:";
	consoleOut(rowUpperLeft + 3, colUpperLeft + 11) << level;
	consoleOut(rowUpperLeft + 3, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 4, colUpperLeft) << "#   Score:";
	consoleOut(rowUpperLeft + 4, colUpperLeft + 11) << score;
	consoleOut(rowUpperLeft + 4, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 5, colUpperLeft) << "#   Suns:";
	consoleOut(rowUpperLeft + 5, colUpperLeft + 11) << sunQuantity;
	consoleOut(rowUpperLeft + 5, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 6, colUpperLeft) << "#";
	consoleOut(rowUpperLeft + 6, colUpperLeft + 22) << "#";
	consoleOut(rowUpperLeft + 7, colUpperLeft) << "#######################";
}