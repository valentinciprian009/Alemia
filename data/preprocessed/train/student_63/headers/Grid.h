#pragma once
#include "Field.h"
class Grid
{
	Field cube;
	std::vector<Field>cage;
public:
	Grid();
	Grid(int x, int y);
	void print_cage();
	void change_core(int linie, int col, char c);
	std::vector<Field> get_cage() { return cage; }
	~Grid();
};

