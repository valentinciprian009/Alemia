#pragma once
#include "Plants.h"

class Wall_nut : public Plants
{
private:
	int hit_points = 144;
	int cost = 50;
	string symbol = "Wn";
	int color_symbol = 14;
	int order_number = 4;

public:
	void take_damage(int x = 0) override;
	int get_hp() override;
	int get_order_number() override;
	int get_cost() override;
	void color(int color_symbol) override;
	void set_cursor(int x, int y) override;
	void print_on_terrain(int x, int y) override;

	Wall_nut() {};
	virtual ~Wall_nut() {};

};