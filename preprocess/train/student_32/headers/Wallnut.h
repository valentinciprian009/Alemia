#pragma once
#include "Plants.h"
class Wallnut :
	public Plants
{
public:
	Wallnut(string nume, int viata, int pret, int rand, int coloana);
	int get_health();
	int get_col();
    int get_row();
	int get_price();
	void set_col(int x);
	void set_row(int y);
    string get_name();
	bool delay();
	void take_damage(int dmg);
};

