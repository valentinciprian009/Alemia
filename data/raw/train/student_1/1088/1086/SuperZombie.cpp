#include"SuperZombie.h"

SuperZombie::SuperZombie(int row_ul, int col_ul, int ln, int stop) : Zombie(row_ul, col_ul, ln, MAX_HEALTH_SUPERZOMBIE, DAMAGE_SUPERZOMBIE, MOVE_SPEED_SUPERZOMBIE, stop, 4) { Log::getInstance().write("SuperZombie created"); jump = 1; }

void SuperZombie::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << " $";
	consoleOut(rowUpperLeft + 1, colUpperLeft) << "-|";
	consoleOut(rowUpperLeft + 2, colUpperLeft) << "/\\";
}