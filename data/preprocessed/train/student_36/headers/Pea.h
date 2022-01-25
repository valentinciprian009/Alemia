#pragma once
#include "Projectiles.h"

class Pea : public Projectiles
{
protected:
	static Pea* mpInstance;

	int damage = 1;
	string symbol = "==";
	int color_symbol = 10;
	 
	Pea() {};
	virtual ~Pea() {};

public:
	static Pea& getInstance();

	int get_damage();
	void color(int color_symbol);
	void set_cursor(int x, int y);
	void print_on_terrain(int x, int y);

};