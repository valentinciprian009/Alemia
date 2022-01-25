#pragma once
#include "Zombie.h"

class Normal_Zombie : public Zombie
{
private:
	int hit_points = 10;
	int speed = 5;
	int damage = 2;
	int points = 1;
	int color_symbol = 7;
	string symbol = "NZ";
	int order_number = 10;

public:
	void take_damage(int x);
	int get_hp() override;
	int get_points() override;
	void color(int color_symbol);
	void set_cursor(int x, int y);
	void print_on_terrain(int x, int y);
	void change_jump() {};
	int get_jump() { return 0; };

	Normal_Zombie() {};
	virtual ~Normal_Zombie() {};

};