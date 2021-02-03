#include "flower_bar.h"

Flower_bar::Flower_bar()
{
	for (int i = 0; i < tiles_num; i++)
	{
		flower_tile_vec[i] = new Flower_tile(i+1);
	}

}
void Flower_bar::Draw(int x, int y)
{
	int last_y;
	int delim = 1;

	conOut(x, y) << "Plants: ";

	int i;
	for (i = 0; i < tiles_num; i++) {
		flower_tile_vec[i]->Draw(x, y + 2 + i * Flower_tile::height);
		
	}

	last_y = y + 1 + i * Flower_tile::height;

	Flower_bar::draw_selected(x, last_y);
}

void Flower_bar::draw_selected(int x, int y)
{
	
	conOut(x, y+1) << "Selected: ";
	if (has_selected) {
		conOut(x, y + 2) << "                     ";
		flower_tile_vec[sel_index]->Draw(x, y + 3);
	}
	else {
		conOut(x, y + 2) << "None selected ";
		conOut(x, y + 3) << "             ";
		conOut(x, y + 4) << "             ";
		conOut(x, y + 5) << "             ";

	}
}

void Flower_bar::activate_selector(COORD coord)
{
	for (int i = 0; i < tiles_num; i++)
	{
		if (flower_tile_vec[i]->isClicked(coord))
		{
		
				sel_index = i;
				has_selected = true;
			
		}
	}

	

}