#pragma once
#include <string>
#include "Draw.h"
class CherryBomb :public Draw
{
	int viata;
	
public:
	CherryBomb();
	CherryBomb(int viata) :viata(viata) {};
	void draw(int x,int y);
	
	~CherryBomb();
};

