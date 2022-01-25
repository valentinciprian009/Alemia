#pragma once
#pragma once
#include "entity.h"
#include <chrono>
class frozen_pea :public entity
{
public:
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
	static const int move_speed = 1;
	static const int damage = 50;


	frozen_pea(int x, int y) :entity::entity(x, y) {
		name = "pea";
		begin = std::chrono::steady_clock::now();
		end = std::chrono::steady_clock::now();
	}



	virtual void print()
	{
		entity::print();

		SetConsoleTextAttribute(conOut.handle, FOREGROUND_BLUE);

		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 3) << 0;

		SetConsoleTextAttribute(conOut.handle, 7);
	}

	virtual void run(std::vector<entity*>& L, bool* L_mod, int i, int& sunflower_nr, int& score) {

		end = std::chrono::steady_clock::now();
		for (int j = 0; j < 7 - i; j++)
		{
			if (std::chrono::duration_cast<std::chrono::seconds>(end - this->begin).count() > j* move_speed + move_speed)
			{
				if (i == 7) {
					L[i]->clear();
					L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
					L[i]->print();
					return;
				}
				else if (L[i + 1]->name == "pea") {
					this->begin = std::chrono::steady_clock::now();
					return;
				}
				else if (L[i + 1 + j]->name == "entity") {
					this->begin = std::chrono::steady_clock::now();
					L[i]->clear();
					L[i + 1 + j] = new frozen_pea(L[i]->LEFT_DOWN_x + 10 + j * 10, L[i]->LEFT_DOWN_y);
					L[i + 1 + j]->print();
					L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
					return;
				}
				else if ((L[i + 1 + j]->name == "zombie") || (L[i + 1 + j]->name == "SuperZombie") || (L[i + 1 + j]->name == "PoleVaultingZombie") || (L[i + 1 + j]->name == "BucketHeadZombie")) {
					this->begin = std::chrono::steady_clock::now();
					L[i]->clear();
					L[i + 1 + j]->health -= damage;
					L[i+1+j]->begin= std::chrono::steady_clock::now();
					if (L[i + 1 + j]->health <= 0) {
						L[i + 1 + j]->clear();
						score += L[i + 1 + j]->score;
						L[i + 1 + j] = new entity(L[i + 1 + j]->LEFT_DOWN_x, L[i + 1 + j]->LEFT_DOWN_y);
					}
					L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
					return;
				}
			}
		}
	}
};



