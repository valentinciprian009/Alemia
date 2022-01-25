#pragma once
#include "Draw.h"
#include <string>
class Sunflower :public Draw
{
	int viata;
	
public:
	Sunflower();
	Sunflower(int viata): viata(viata) {};
	void draw(int x,int y);
	
	~Sunflower();
};

