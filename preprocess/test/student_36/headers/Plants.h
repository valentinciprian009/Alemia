#pragma once
#include "Entities.h"

class Plants : public Entities
{
public:
	virtual void take_damage(int x = 0) = 0;
	virtual int get_hp() = 0;
	virtual int get_points() { return 0; };
	virtual int get_order_number() =0;
	virtual int get_cost() =0;
	virtual void color(int color_symbol) = 0;
	virtual void set_cursor(int x, int y) = 0;
	virtual void print_on_terrain(int x, int y) = 0;
	virtual void change_jump() {};
	virtual int get_jump() { return 0; };

};