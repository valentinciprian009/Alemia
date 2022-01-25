#pragma once
#include "Plants.h"

class Peashooter : public Plants
{
protected:
	int attack_speed = 2;
	int hit_points = 8;
	int cost = 100;
	string symbol = "Ps";
	int color_symbol = 2;
	int order_number = 1;

public:
	void take_damage(int x = 0) override;
	int get_hp() override;
	int get_order_number() override;
	int get_cost() override;
	void color(int color_symbol) override;
	void set_cursor(int x, int y) override;
	virtual void print_on_terrain (int x, int y) override;
	
	Peashooter() {};
	virtual ~Peashooter() {};

};