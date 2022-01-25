#pragma once
#include "Plant.h"
class wall_nut : public Plant
{
	public:
		wall_nut(int x, int y) : Plant::Plant(x, y) {
			health = 200;
			name = "wall_nut";
		}

		static const int reuse_time = 5;
		static const int cost = 50;

		virtual void print()
		{
			entity::print();
			SetConsoleTextAttribute(conOut.handle, 102);
			conOut(LEFT_DOWN_y - 3, LEFT_DOWN_x + 6) << "||";
			conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 6) << "||";
			conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 6) << "||";
			SetConsoleTextAttribute(conOut.handle, 7);
		}

};

