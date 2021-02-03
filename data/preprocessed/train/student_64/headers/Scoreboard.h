#pragma once
#include "Square.h"
#include "ConsoleOutput.h"
#include <Windows.h>

class Scoreboard :
	public Square
{
public:
	int points = 0;
public:
	Scoreboard();
	~Scoreboard();

	void PrintInteriorValue();
};

