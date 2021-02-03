#include "DrawableZombie.h"



DrawableZombie::DrawableZombie()
{
}

void DrawableZombie::draw(int row, int col)
{
	conOut(row, col) << "@";
	conOut(row+1, col) << "/\\";
	conOut(row+2, col) << "/\\";
}

void DrawableZombie::delete_draw(int row, int col)
{
	
		conOut(row, col - 1) << "   ";
		conOut(row + 1, col - 1) << "   ";
		conOut(row + 2, col - 1) << "   ";
}


DrawableZombie::~DrawableZombie()
{
}
