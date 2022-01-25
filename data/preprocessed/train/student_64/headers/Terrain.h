#pragma once
#include "ConsoleOutput.h"
#include <Windows.h>
#include "Square.h"
#include "Scoreboard.h"
#include"Projectile.h"
#include<vector>

class Terrain
{
public:
	Scoreboard scoreBoard;
	Square suns[8];
	Square plants[5];
	Square mainZone[5][8];
public:

	Terrain();
	~Terrain();

	void PrintScore();
	void init();
};

