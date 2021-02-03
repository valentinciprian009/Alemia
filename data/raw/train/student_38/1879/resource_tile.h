#pragma once
#include<iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#define parcel 4

class Tile
{

public:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

	int x, y;
	static const int width = 3, height = 3;
	int id;
	bool has_sun;


	Tile();
	void Draw(int x, int y);
	bool isClicked(COORD coord);

	bool eat_sun(COORD cord);

};

