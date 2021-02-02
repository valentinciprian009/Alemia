#pragma once
#include "Resources.h"

class Sun : public Resources
{
private:
	vector<int> vector_sun;
	string symbol= "*";
	int color_symbol = 14;
	int money = 50;

public:
	 void print_sun();
	 void set_sun();
	 void color(int color_symbol);
	 void set_cursor(int x, int y);
	 void print_on_terrain(int x, int y) {};

	 Sun();
	 virtual ~Sun() {};

};