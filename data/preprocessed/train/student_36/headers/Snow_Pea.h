#pragma once
#include "Peashooter.h"

class Snow_Pea : public Peashooter
{
private:
	int attack_speed = 2;
	int slow = 1;
	int hit_points = 8;
	int cost = 175;
	string symbol = "SP";
	int color_symbol = 1;
	int order_number = 5;
	
public:
	void take_damage(int x = 0) override;
	int get_hp() override;
	int get_order_number() override;
	int get_cost() override;
	void color(int color_symbol) override;
	void set_cursor(int x, int y) override;
	void print_on_terrain(int x, int y) override;
	

	Snow_Pea() : Peashooter() {};
	virtual ~Snow_Pea() {};

};