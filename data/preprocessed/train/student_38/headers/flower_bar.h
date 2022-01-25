#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "flower_tile.h"
class Flower_bar
{

private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

	const int tiles_num = 5;
	Flower_tile *flower_tile_vec[5];
	
	


public:
	Flower_bar();
	int  sel_index;
	bool has_selected = false;
	void Draw(int x, int y);
	void draw_selected(int x, int y);
	void activate_selector(COORD coord);

};

