#pragma once
#include"garden_line.h"
class Garden
{

public:
	Garden_line lines[5];
	int x, y;
	static const int width = 2 * 5 * Garden_tile::width + 12;
	
	static Garden& getInstance() { Garden* g = new Garden; return *g; };
	void Draw(int x, int y);
	COORD get_selected_tile(COORD coord);
	void place_flower_at(int x, int y, int type);
	void update_bullets();

};

