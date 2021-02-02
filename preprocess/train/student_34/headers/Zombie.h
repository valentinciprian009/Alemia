#pragma once
#include <iostream>	
#include "Draw.h"
class Zombie
{
	int x;
	int y;
	int health;
public:
	Zombie();
	void draw(int x, int y);
	void delete_(int x, int y);
	void set_x(int x1) { x = x1; }
	void set_y(int y1) { y = y1; }
	int get_x() { return x; }
	int get_y() { return y; }
	void set_health(int h) { health = h; }

	int get_health() { return health; }
	~Zombie();
};

