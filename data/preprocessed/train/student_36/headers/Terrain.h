#pragma once
#include "Entities.h"

class Terrain : public Entities
{
private:
	static Terrain* mpInstance;
	
	int color_symbol = 8;

	Terrain() {};
	virtual ~Terrain() {};

public:
	static Terrain& getInstance();

	virtual void take_damage(int x = 0) {};
	virtual int get_hp() { return 0; };
	virtual int get_points() { return 0; };
	void color(int color_symbol);
	void gotoXY(int x, int y);
	void set_cursor(int x, int y) {};
	void print_on_terrain(int x, int y);
	virtual void change_jump() {};
	virtual int get_jump() { return 0; };

};