#pragma once
#pragma once

#include <Windows.h>
#include<iostream>;
class terrain
{
	int x_grass = 50;
	int y_grass = 8;
	int x_space = 7;
	int y_space = 4;
	int level;
	int x_plant = 42;
	int x1_plant = 120;
	int y_plant = 4;
	int x_sun = 42;
	int y_sun = 4;
	int x_scoreboard;
	int y_scoreboard;
public:

	void setlevel(int n);
	int getlevel();
	int getx_grass();
	int gety_grass();
	int getx_space();
	int gety_space();
	int getx_plant();
	int gety_plant();
	int getx_sun();
	int gety_sun();


};



