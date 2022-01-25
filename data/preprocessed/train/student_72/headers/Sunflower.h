#pragma once
#include"Plant.h"

class Sunflower :public Plant
{
public:
	Sunflower(int x, int y) : Plant::Plant(x, y) {
		name = "Sunflower";
		health = 100;
	}
	static const int reuse_time = 5;
	static const int cost = 10;

	virtual void print() 
	{
		entity::print();
		SetConsoleTextAttribute(conOut.handle, 14);
		conOut(LEFT_DOWN_y - 3, LEFT_DOWN_x + 5) <<   "-";
		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 4) <<  "-0-";
		SetConsoleTextAttribute(conOut.handle, 238);
		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 5) << "0";
		conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 5) << "0";
		SetConsoleTextAttribute(conOut.handle, 7);
	}
};

