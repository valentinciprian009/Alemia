#pragma once
#include "Plants.h"
class Sunflower :
	public Plants
{
public:
	 Sunflower(string name,int row,int col,int health,int price);
	 void set_col(int x);
	 void set_row(int x);
	 int get_price();
	 int get_health();
	 int get_col();
	 int get_row();
	 string get_name();
	 bool delay();
	 void take_damage(int dmg);
};

