#include "DrawablePlant.h"



DrawablePlant::DrawablePlant()
{
}

void DrawablePlant::draw(int row,int col)
{

		conOut(row,col) << "\\Q/";
		row += 6;
		conOut(row, col)<< "~O~";
		row += 6;
		conOut(row, col) << " @";
		row += 6;
		conOut(row, col) << "|W|";
		row += 6;
		conOut(row, col) << "\\Q~/";
}


DrawablePlant::~DrawablePlant()
{
}
