#pragma once
#include "Draw.h"
class Snow_Pea :public Draw
{ 
	int viata;
	
public:
	Snow_Pea();
	Snow_Pea(int viata) :viata(viata) {};
	void draw(int x, int y);
	
	~Snow_Pea();
};

