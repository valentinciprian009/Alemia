#pragma once
#include "Character.h"

class Field
{
	Character personaj;
	int row;
	int col;
public:
	Field();

	Field(int row, int col) : row(row), col(col) {}

	int getRow() { return row; }
	int getCol() { return col; }

	void addCharacter(Character &c) { personaj = c;}

	Character getCharacter() { return personaj; }

	~Field();
};

