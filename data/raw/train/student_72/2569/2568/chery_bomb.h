#pragma once
#include "Plant.h"
class chery_bomb:public Plant
{
	public:
		int damage = 50;
		chery_bomb(int x, int y) : Plant::Plant(x, y) {
			name = "chery_bomb";
			health = 100;
			begin = std::chrono::steady_clock::now();
			end = std::chrono::steady_clock::now();
		}
		static const int reuse_time = 5;
		static const int cost = 30;

		virtual void print()
		{
		entity::print();
		SetConsoleTextAttribute(conOut.handle,  FOREGROUND_GREEN);
		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 4) << "| |";
		SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED | FOREGROUND_RED);
		conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 4) << "0";
		conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 6) << "0";
		SetConsoleTextAttribute(conOut.handle, 7);
		}

		virtual void run(std::vector<entity*>& L, bool* L_mod, int i, int& sunflower_nr, int& score)
		{
			end = std::chrono::steady_clock::now();
			if (std::chrono::duration_cast<std::chrono::seconds>(end - this->begin).count() > 1)
			{
				L[i]->clear();
				L[i]= new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
				for (int j = -2; j < 5; j++)
				{
					if ((j != 0)&&(i+j>=0)&&(i+j<=7))
					{
						if ((L[i + j]->name == "zombie") || (L[i + j]->name == "SuperZombie") || (L[i + j]->name == "PoleVaultingZombie") || (L[i + j]->name == "BucketHeadZombie"))
						{
							if ((j == 1) || (j == -1)){
								L[i + j]->health -= chery_bomb::damage;
							}
							else{
								L[i + j]->health -= chery_bomb::damage/2;
							}

							if (L[i + j]->health <= 0) {
								L[i + j]->clear();
								score += L[i + j]->score;
								L[i + j] = new entity(L[i + j]->LEFT_DOWN_x, L[i + j]->LEFT_DOWN_y);
							}
						}
					}
				}
			}
		}
}	;

