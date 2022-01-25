#pragma once
#include"entity.h"

class sun :public entity
{
	public:
		static const int resorce = 50;

		sun(int x, int y) : entity::entity(x, y) {}

		virtual void print()
		{
			entity::print();

			SetConsoleTextAttribute(conOut.handle, 14 );
			conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 4) << "--";
			conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 3) << "----";
			conOut(LEFT_DOWN_y - 3, LEFT_DOWN_x + 4) << "--";
			SetConsoleTextAttribute(conOut.handle, 238);
			conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 4) << "--";
			SetConsoleTextAttribute(conOut.handle, 7);
		}
};

