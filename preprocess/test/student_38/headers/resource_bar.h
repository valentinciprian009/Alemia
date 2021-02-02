#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "resource_tile.h"
class Resource_bar
{

private:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

	const int tiles_num = 8;
	Tile tile_vec[8];
	

public:
	int score;
	Resource_bar():score(10){
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	};
	void Draw(int x, int y);
	void taken_resource(COORD cord);
	void generate_resource();
	int get_score() { return score; };
	

};

