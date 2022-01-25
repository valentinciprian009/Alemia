#include "garden.h"
#include<iostream>
#include<string>
void Garden::Draw(int x, int y)
{
	this->x = x;
	this->y = y;
	int delim = 1;

	for (int i = 0; i < 5; i++)
		lines[i].Draw(x, y + i * (Garden_tile::height+delim));


}

COORD Garden::get_selected_tile(COORD coord)
{
	COORD c;
	c.X = -1;
	c.Y = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++)
			if (lines[i].tiles[j].is_clicked(coord))
			{
				c.X = i;
				c.Y = j;
				return c;
			}
	}

	return c;
}


void Garden::place_flower_at(int x, int y, int type)
{

	lines[x].tiles[y].place_flower(type);

}

void Garden::update_bullets()
{
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++)
			if (lines[i].tiles[j].has_flower)
			{
			
				if (lines[i].tiles[j].bullet_x + 2 > (this->width - lines[i].tiles[j].fl->x)+this->x+10)
				{
					lines[i].tiles[j].clear_prev_bullet(lines[i].tiles[j].bullet_x);
					lines[i].tiles[j].bullet_x = 0;
				}
				lines[i].tiles[j].bullet_x+=2;
				lines[i].tiles[j].draw_bullet(lines[i].tiles[j].bullet_x);
				lines[i].tiles[j].clear_prev_bullet(lines[i].tiles[j].bullet_x-2);
				
			
			}
	}

}