#pragma once
#include "Draw.h"
#include<string>
#include "Pea.h"
#include <iostream>
class Peashooter :public Draw
{
	int viata;
public:
	Peashooter();
	Peashooter(int viata) :viata(viata){ };
	void draw(int x,int y);
	void shoot(int x, int y, Pea pea);
	~Peashooter();
};

