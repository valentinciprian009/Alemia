#pragma once
#include "Zombie.h"

class BucketHead_Zombie : public Zombie
{
private:
	int hit_points = 35;
	int speed = 5;
	int damage = 2;
	int points = 2;
	int color_symbol = 7;
	string symbol = "BZ";
	int order_number = 11;

public:
	void take_damage(int x);
	int get_hp() override;
	int get_points() override;
	void color(int color_symbol);
	void set_cursor(int x, int y);
	void print_on_terrain(int x, int y);
	void change_jump() {};
	int get_jump() { return 0; };

	BucketHead_Zombie() {};
	virtual ~BucketHead_Zombie() {};

};