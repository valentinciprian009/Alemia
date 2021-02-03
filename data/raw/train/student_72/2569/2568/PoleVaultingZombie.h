#pragma once
#include "zombie.h"
class PoleVaultingZombie:virtual public zombie
{
public:
	bool jumped;
	PoleVaultingZombie(int x, int y) :zombie::zombie(x, y) {
		name = "PoleVaultingZombie";
		score = 150;
		jumped = false;
	}
	virtual void print()
	{
		entity::print();

		SetConsoleTextAttribute(conOut.handle, BACKGROUND_BLUE | FOREGROUND_BLUE);
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
			else if (L[i - 1]->name == "entity") {
				this->begin = std::chrono::steady_clock::now();
				L[i]->clear();
				L[i - 1] = new PoleVaultingZombie(L[i]->LEFT_DOWN_x - 10, L[i]->LEFT_DOWN_y);
				L[i - 1]->health = L[i]->health;
				L[i - 1]->print();
				L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
				return;
			}
			else if (i > 2)
			{
				if ((L[i - 2]->name == "entity") && (L[i - 1]->name != "entity") && (jumped == false)) {
					jumped = true;
					this->begin = std::chrono::steady_clock::now();
					L[i]->clear();
					L[i - 2] = new PoleVaultingZombie(L[i]->LEFT_DOWN_x - 20, L[i]->LEFT_DOWN_y);
					L[i - 2]->health = L[i]->health;
					L[i - 2]->print();
					L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
					return;
				}
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
				L[i - 1] = new PoleVaultingZombie(L[i]->LEFT_DOWN_x - 10, L[i]->LEFT_DOWN_y);
				L[i - 1]->health = L[i]->health;
				L[i - 1]->health -= Pea::damage;
				if (L[i - 1]->health <= 0) {
					score += L[i -1]->score;
					L[i - 1]->clear();
					L[i - 1] = new entity(L[i - 1]->LEFT_DOWN_x, L[i - 1]->LEFT_DOWN_y);
				}
				L[i - 1]->print();
				L[i] = new entity(L[i]->LEFT_DOWN_x, L[i]->LEFT_DOWN_y);
				return;
			}
			
		}
	}
};

