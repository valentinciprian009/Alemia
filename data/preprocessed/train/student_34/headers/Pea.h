#pragma once
#include "Draw.h"
class Pea :public Draw
{
	int power;
	int x;
	int y;
public:
	Pea();
	void set_x(int x1) { x = x1; }
	void set_y(int y1) { y = y1; }
	int get_x() { return x; }
	int get_y() { return y; }
	Pea(int power) :power(power) {};
	void draw(int x, int y);
	int get_power() { return power; }
	~Pea();
};

