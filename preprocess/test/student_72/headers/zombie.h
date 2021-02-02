#pragma once
#include "entity.h"
#include <chrono>
#include "Pea.h"

class zombie :public entity
{
	public:
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;
		int damage;

	zombie(int x, int y) :entity::entity(x, y) {
		health = 100;
		damage = 50;
		score = 100;
		name = "zombie";
		begin = std::chrono::steady_clock::now();
		end = std::chrono::steady_clock::now();
	}

	virtual void print()
	{
		entity::print();

		SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);
		conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x + 4) << "--";
		conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x + 3) << "----";
		conOut(LEFT_DOWN_y - 3, LEFT_DOWN_x + 4) << "--";
		SetConsoleTextAttribute(conOut.handle, 7);

		
	}

	virtual void run(std::vector<entity*>& L, bool* L_mod, int i, int& sunflower_nr, int& score)
	{
		end = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end - this->begin).count() > 1) {
			if (i == 0)
			{
				system("pause");
			}
			else if (L[i-1]->name == "entity") {
				this->begin = std::chrono::steady_clock::now();
				L[i]->clear();
				L[i - 1] = new zombie(L[i]->LEFT_DOWN_x - 10, L[i]->LEFT_DOWN_y);
				L[i - 1]->health = L[i]->health;
				L[i - 1]->print();
				L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
				return;
			}
			else if ((L[i - 1]->name == "Peashooter") || (L[i - 1]->name == "snow_pea") || (L[i - 1]->name == "wall_nut") || (L[i - 1]->name == "Sunflower") || (L[i - 1]->name == "chery_bomb")) {
				this->begin = std::chrono::steady_clock::now();
				L[i - 1]->health -= damage;
				if (L[i - 1]->health <= 0) {
					if (L[i - 1]->name == "Sunflower") {
						sunflower_nr--;
					}
					L[i - 1]->clear();
					L[i - 1] = new entity(L[i - 1]->LEFT_DOWN_x, L[i - 1]->LEFT_DOWN_y);
				}
				return;
			}
			else if ((L[i - 1]->name == "pea") || (L[i - 1]->name == "frozen_pea"))
			{
				this->begin = std::chrono::steady_clock::now();
				L[i]->clear();
				L[i - 1] = new zombie(L[i]->LEFT_DOWN_x - 10, L[i]->LEFT_DOWN_y);
				L[i - 1]->health = L[i]->health;
				L[i - 1]->health -= Pea::damage;
				if (L[i - 1]->health <= 0) {
					L[i - 1]->clear();
					score += L[i - 1]->score;
					L[i - 1] = new entity(L[i - 1]->LEFT_DOWN_x, L[i - 1]->LEFT_DOWN_y);
				}
				L[i - 1]->print();
				L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
				return;
			}
		}
	}
};

