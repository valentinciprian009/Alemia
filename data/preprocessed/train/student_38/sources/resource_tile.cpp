#include "resource_tile.h"


Tile::Tile()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	has_sun = false;
}

void Tile::Draw(int x, int y)
{
	this->x = x;
	this->y = y;

	


	std::string text;

	text += "...";

	conOut(x,y+2) << text;
	if (this->has_sun)
	{
		conOut.change_color("yellow");
		conOut(this->x + 1, this->y + 1) << "*";
		conOut.change_color("white");
	}
	else
		conOut(this->x + 1, this->y + 1) << " ";


}

bool Tile::isClicked(COORD coord)
{

	COORD mouse_p;
	mouse_p = coord;

	if (mouse_p.X >= 0)
	{
		if (mouse_p.X >= x && mouse_p.X <= x + width)
			if (mouse_p.Y >= y && mouse_p.Y <= y + height )
				return true;

	}


	return false;

}

bool Tile::eat_sun(COORD coord)
{
	if (this->isClicked(coord))
	{
		has_sun = false;

		return true;

	}

	return false;

}