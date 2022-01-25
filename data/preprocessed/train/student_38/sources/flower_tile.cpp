#include "flower_tile.h"

void Flower_tile::Draw(int x , int y)
{
	this->x = x;
	this->y = y;
   
	fl->Draw(x + 1, y);

	conOut(x+3, y+1) << fl->getPrice()<<" ";
    conOut(x, y + 2) << "_____";

}

bool Flower_tile::isClicked(COORD coord)
{

	COORD mouse_p;
	mouse_p = coord;

	if (mouse_p.X >= 0)
	{
		if (mouse_p.X >= x && mouse_p.X <= x + width)
			if (mouse_p.Y >= y && mouse_p.Y <= y + height-2)
				return true;
			
	}


	return false;

}