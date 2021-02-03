#pragma once
#include "Draw.h"
class WallNut:public Draw
{
	int viata;
	
public:
	WallNut();
	WallNut(int viata) :viata(viata) {};
	void draw(int x, int y);
	~WallNut();
};

