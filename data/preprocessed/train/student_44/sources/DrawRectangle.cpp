#include "DrawRectangle.h"

int pthh(int x, int y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

DrawRectangle::DrawRectangle()
{
}

void DrawRectangle::draw(int row, int col)
{
	int r = 2;

	const int width = r;
	const int length = r * 1.5;

	for (int x = width; x >= -width; x -= 1) {
		for (int y = -length; y <= length; y++) {

			if ((int)pthh(x, y) == r)
				conOut(row+x,col +y) << "*";
			else conOut(row+x, col+y) << " ";

		}
	}
}

void DrawRectangle::draw_score(int row, int col)
{
	{
		int r = 2;

		const int width = r;
		const int length = r * 1.5;

		for (int x = width; x >= -width; x -= 1) {
			for (int y = -length; y <= length; y++) {

				if ((int)pthh(x, y) == r)
					conOut(row + x, col + y + 1) << "*";
				else conOut(row + x, col + y) << " ";

			}
		}
	}

}
DrawRectangle::~DrawRectangle()
{
}
