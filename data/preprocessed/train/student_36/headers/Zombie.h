#pragma once
#include "Entities.h"

class Zombie : public Entities
{
public:
	virtual void take_damage(int x) {};
	virtual int get_hp() { return 0; };
	virtual int get_points() { return 0; };
	virtual void color(int color_symbol) = 0;
	virtual void set_cursor(int x, int y) = 0;
	virtual void print_on_terrain(int x, int y) = 0;
	virtual void change_jump() = 0;
	virtual int get_jump() = 0;

};