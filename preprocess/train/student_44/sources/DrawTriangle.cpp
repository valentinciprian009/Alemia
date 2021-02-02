#include "DrawTriangle.h"



DrawTriangle::DrawTriangle()
{
}

void DrawTriangle::draw(int col, int row)
{
	//48 cu 9
	row = row - 2;
	conOut(col + 1, row + 1) << "*";
	conOut(col + 1, row + 2) << "*";
	conOut(col + 1, row + 3) << "*";
	conOut(col + 1, row + 4) << " ";
	conOut(col + 1, row + 5) << "*";
	conOut(col + 1, row + 6) << "*";
	conOut(col + 1, row + 7) << "*";

	conOut(col + 2, row + 1) << "*";
	conOut(col + 2, row + 2) << "*";
	conOut(col + 2, row + 3) << " ";
	conOut(col + 2, row + 4) << " ";
	conOut(col + 2, row + 5) << " ";
	conOut(col + 2, row + 6) << "*";
	conOut(col + 2, row + 7) << "*";

	conOut(col + 3, row + 1) << "*";
	conOut(col + 3, row + 2) << " ";
	conOut(col + 3, row + 3) << " ";
	conOut(col + 3, row + 4) << " ";
	conOut(col + 3, row + 5) << " ";
	conOut(col + 3, row + 6) << " ";
	conOut(col + 3, row + 7) << "*";
	//parte jos
	conOut(col + 4, row + 1) << "*";
	conOut(col + 4, row + 2) << "*";
	conOut(col + 4, row + 3) << " ";
	conOut(col + 4, row + 4) << " ";
	conOut(col + 4, row + 5) << " ";
	conOut(col + 4, row + 6) << "*";
	conOut(col + 4, row + 7) << "*";

	conOut(col + 5, row + 1) << "*";
	conOut(col + 5, row + 2) << "*";
	conOut(col + 5, row + 3) << "*";
	conOut(col + 5, row + 4) << " ";
	conOut(col + 5, row + 5) << "*";
	conOut(col + 5, row + 6) << "*";
	conOut(col + 5, row + 7) << "*";




	//conOut(col + 3,row + 8) << "*";
}


DrawTriangle::~DrawTriangle()
{
}
