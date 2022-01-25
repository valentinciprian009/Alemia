#include "garden_line.h"

void Garden_line::Draw(int x, int y)
{
	this->x = x;
	this->y = y;
	int delim = 2;
	for (int i = 0; i < 8; i++)
		tiles[i].Draw(x+ i * Garden_tile::width * delim, y);


}
