#include "resource_bar.h"

void Resource_bar::Draw(int x,int y)
{
	for (int i = 0; i < tiles_num; i++)
		tile_vec[i].id = i;

	conOut(x, y+2) << "Resources: ";
	int text_len = 13;

	int delim = 2;
	for (int i = 0; i < tiles_num; i++)
		tile_vec[i].Draw(x+ text_len + i * Tile::width * delim, y);

}



void Resource_bar::taken_resource(COORD coord)
{
	for (int i = 0; i < tiles_num; i++)
		if (tile_vec[i].eat_sun(coord))
			this->score+=2;


}

void Resource_bar::generate_resource()
{
	int min = 1;
	int max = 9;
	int index = (int) (min + (rand() % static_cast<int>(max - min + 1)));
	index = index - 1;
	

	tile_vec[index].has_sun = true;


}