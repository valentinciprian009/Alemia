#pragma once
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"

class Super_Zombie : virtual public BucketHead_Zombie, virtual public PoleVaulting_Zombie
{
private:
	int hit_points = 35;
	int speed = 7;
	int damage = 2;
	int points = 5;
	int color_symbol = 7;
	string symbol = "SZ";
	int order_number = 13;
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

	Super_Zombie() {};
	virtual ~Super_Zombie() {};

};