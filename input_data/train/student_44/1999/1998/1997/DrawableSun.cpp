#include "DrawableSun.h"



DrawableSun::DrawableSun()
{
}

void DrawableSun::draw(int row, int col)
{
	
	conOut(row, col-2) << "_\\|/_";
	conOut(row + 1, col-1) << "/|\\" ;
}

void DrawableSun::getSun(int row, int col)
{
	conOut(row, col - 2) << "     ";
	conOut(row + 1, col - 1) << "    ";
}


DrawableSun::~DrawableSun()
{
}
