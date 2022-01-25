#pragma once
#include "Zombie.h"

class PoleVaulting_Zombie : public Zombie
{
private:
	int hit_points = 16;
	int speed = 7;
	int damage = 2;
	int points = 2;
	int color_symbol = 7;
	string symbol = "PZ";
	int order_number = 12;
	int jump = 1;

public:
	void take_damage(int x);
	int get_hp() override;
	int get_points() override;
	void color(int color_symbol);
	void set_cursor(int x, int y);
	void print_on_terrain(int x, int y);
	void change_jump();
	int get_jump();

	PoleVaulting_Zombie() {};
	virtual ~PoleVaulting_Zombie() {};

};