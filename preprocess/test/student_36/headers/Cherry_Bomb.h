#pragma once
#include "Plants.h"

class Cherry_Bomb : public Plants
{
private:
	int damage = 8;
	int cost = 150;
	string symbol = "CB";
	int color_symbol = 4;
	int order_number = 3;

public:
	void take_damage(int x = 0) override {};
	int get_hp() override { return 0; };
	int get_order_number() override;
	int get_cost() override;
	void color(int color_symbol) override {};
	void set_cursor(int x, int y) override;
	void print_on_terrain(int x, int y) override {};

	int give_damage();

	Cherry_Bomb() {};
	virtual ~Cherry_Bomb() {};

};