#pragma once
#include "Plant.h"
#include "frozen_pea.h"
class snow_pea :public Plant
{
public:
	int move_speed = 1;
	snow_pea(int x, int y) :Plant::Plant(x, y) {
		name = "snow_pea";
		health = 100;
	}

	static const int reuse_time = 5;
	static const int cost = 40;

	virtual void print()
	{
		entity::print();

		SetConsoleTextAttribute(conOut.handle, BACKGROUND_BLUE | FOREGROUND_BLUE);

		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 4) << "00";
		conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 3) << "0000";

		SetConsoleTextAttribute(conOut.handle, FOREGROUND_BLUE);
		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 6) << "---";
		SetConsoleTextAttribute(conOut.handle, 7);
	}

	virtual void run(std::vector<entity*>& L, bool* L_mod, int i, int& sunflower_nr, int& score)
	{
		end = std::chrono::steady_clock::now();

		if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 2)
		{
			for (int j = 0; j < 6 - i; j++)
			{
				if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 2 + j * frozen_pea::move_speed)
				{
					if ((L[i + 1 + j]->name != "Peashooter") && (L[i + 1 + j]->name != "chery_bomb") && (L[i + 1 + j]->name != "Sunflower") && (L[i + 1 + j]->name != "wall_nut") && (L[i + 1 + j]->name != "snow_pea")) {
						begin = std::chrono::steady_clock::now();
						L[i + 1 + j] = new frozen_pea(L[i + j + 1]->LEFT_DOWN_x, L[i + j + 1]->LEFT_DOWN_y);
						L[i + 1 + j]->print();
						break;
					}
				}
			}
		}
	};

};