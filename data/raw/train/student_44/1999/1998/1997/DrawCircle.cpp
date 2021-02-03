#include "DrawCircle.h"

DrawCircle::DrawCircle()
{
}

int pth(int x, int y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

void DrawCircle::draw(int row,int col)
{
	int c = 0;
	int r = 3;

	const int width = r;
	const int length = r * 1.5;

	for (int y = width; y >= -width; y -= 2) {
		for (int x = -length; x <= length; x++) {

			if ((int)pth(x, y) == r)
				conOut(row+x, col+y) << "*";
			else conOut(row+x, col+y) << " ";
			
		}
		//conOut(row, col) << "\n";
	}
}

DrawCircle::~DrawCircle()
{
}
