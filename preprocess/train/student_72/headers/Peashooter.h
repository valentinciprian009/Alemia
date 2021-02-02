#pragma once
#include "Plant.h"
#include "Pea.h"
#include <vector>

class Peashooter:public Plant
{
	public:
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;

		Peashooter(int x, int y) :Plant::Plant(x, y) {
			name = "Peashooter";
			health = 100;
			begin = std::chrono::steady_clock::now();
			end = std::chrono::steady_clock::now();
		}

		static const int reuse_time = 5;
		static const int cost = 40;
		virtual void print()
		{
			entity::print();

			SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN|FOREGROUND_GREEN);

			conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 4) << "00";
			conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 3) << "0000";

			SetConsoleTextAttribute(conOut.handle, FOREGROUND_GREEN);
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
					if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 2 + j * Pea::move_speed)
					{
						if ((L[i + 1 + j]->name != "Peashooter") && (L[i + 1 + j]->name != "chery_bomb") && (L[i + 1 + j]->name != "Sunflower") && (L[i + 1 + j]->name != "wall_nut") && (L[i + 1 + j]->name != "snow_pea")) {
							begin = std::chrono::steady_clock::now();
							L[i + 1 + j] = new Pea(L[i + j + 1]->LEFT_DOWN_x, L[i + j + 1]->LEFT_DOWN_y);
							L[i + 1 + j]->print();
							break;
						}
					}
				}
			}
		}
};

