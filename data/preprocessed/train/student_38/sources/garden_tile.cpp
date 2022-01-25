#include "garden_tile.h"

void Garden_tile::Draw(int x, int y)
{
	this->x = x;
	this->y = y;
	conOut.change_color("darkgreen");
	conOut(x, y + height) << "_____";
	conOut.change_color("white");

	
}

bool Garden_tile::is_clicked(COORD coord)
{
	COORD mouse_p;
	mouse_p = coord;

	if (mouse_p.X >= 0)
	{
		if (mouse_p.X >= x && mouse_p.X <= x + width)
			if (mouse_p.Y >= y && mouse_p.Y <= y + height)
				return true;

	}


	return false;

}

void Garden_tile::place_flower(int type)
{

	fl = new Flower(type);
	fl->Draw(this->x, this->y+1);
	has_flower = true;

	/////

}

void Garden_tile::draw_bullet(int move)
{

	if (has_flower)
		bullet.Draw(this->x + 4 + move, this->y + 1);
	else {
		Garden_tile::clear_bullet(this->bullet.x, this->bullet.y);
		this->bullet.x = 0;
		this->bullet.y = 0;
		
	}

}

void Garden_tile::clear_bullet(int x, int y)
{
	conOut(x, y) << " ";
}

void Garden_tile::clear_prev_bullet(int move)
{

	conOut(this->x + 4+move , this->y + 1) << " ";

}