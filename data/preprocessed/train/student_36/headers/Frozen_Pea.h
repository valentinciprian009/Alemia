#pragma once
#include "Pea.h"

class Frozen_Pea : public Pea
{
protected:
	static Frozen_Pea* mpInstance;

	int damage = 1;
	string symbol = "==";
	int color_symbol = 11;

	Frozen_Pea() {};
	virtual ~Frozen_Pea() {};

public:
	static Frozen_Pea& getInstance();

	int get_damage();
	void color(int color_symbol);
	void set_cursor(int x, int y);
	void print_on_terrain(int x, int y);

};