#pragma once
#include "sun.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include<iostream>
#include<vector>
#include "mouse_input.h"
#include <chrono>
class Sun_Spawn_Area
{
private:
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	int first_x;
	int first_y;
	std::chrono::steady_clock::time_point begin_sun ;
	std::chrono::steady_clock::time_point end_sun;

public:
	std::vector<entity*> sun_v;
	std::vector<bool>sun_mod_v;
	int resources;

	Sun_Spawn_Area(int x, int y)
	{
		first_x=x;
		first_y=y;
		begin_sun = std::chrono::steady_clock::now();


		resources = 0;

		for (int i = 0; i < 8; i++) {
			entity* a = new entity(x + i * 10, y);
			sun_v.push_back(a);
			sun_mod_v.push_back(false);
			sun_v[i]->print();
		}

		conOut(first_y - 3, first_x-20) << "score: "; cout << "0  ";
		conOut(first_y - 1, first_x-20) << "resurces: "; cout << "0  ";
		conOut(first_y - 5, first_x - 20) << "Sunflower"; cout << "0  ";
	}

	bool check_inp(mouse_input inp)
	{
		if ((inp.x != 0) && (inp.y != 0))
		{
			if ((inp.y <= sun_v[0]->LEFT_DOWN_y) && (inp.x >= sun_v[0]->LEFT_DOWN_y + 6))
			{
				if ((inp.x >= sun_v[0]->LEFT_DOWN_x) && (inp.x < sun_v[1]->LEFT_DOWN_x)) {
					sun_v[0] = new entity(first_x, first_y);
					sun_mod_v[0] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[1]->LEFT_DOWN_x) && (inp.x < sun_v[2]->LEFT_DOWN_x)) {
					sun_v[1] = new entity(first_x + 10, first_y);
					sun_mod_v[1] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[2]->LEFT_DOWN_x) && (inp.x < sun_v[3]->LEFT_DOWN_x)) {
					sun_v[2] = new entity(first_x + 20, first_y);
					sun_mod_v[2] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[3]->LEFT_DOWN_x) && (inp.x < sun_v[4]->LEFT_DOWN_x)) {
					sun_v[3] = new entity(first_x + 30, first_y);
					sun_mod_v[3] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[4]->LEFT_DOWN_x) && (inp.x < sun_v[5]->LEFT_DOWN_x)) {
					sun_v[4] = new entity(first_x + 40, first_y);
					sun_mod_v[4] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[5]->LEFT_DOWN_x) && (inp.x < sun_v[6]->LEFT_DOWN_x)) {
					sun_v[5] = new entity(first_x + 50, first_y);
					sun_mod_v[5] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[6]->LEFT_DOWN_x) && (inp.x < sun_v[7]->LEFT_DOWN_x)) {
					sun_v[6] = new entity(first_x + 60, first_y);
					sun_mod_v[6] = 1;
					resources += sun::resorce;
					return true;
				}
				else if ((inp.x >= sun_v[7]->LEFT_DOWN_x) && (inp.x < sun_v[7]->LEFT_DOWN_x + 10)) {
					sun_v[7] = new entity(first_x + 70, first_y);
					sun_mod_v[7] = 1;
					resources += sun::resorce;
					return true;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}

	void run(mouse_input inp, int Sunflowe_nr , int score)
	{
		end_sun = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end_sun - begin_sun).count() > (3-Sunflowe_nr/4)) {
			begin_sun = std::chrono::steady_clock::now();
			int pick = rand() % 8;
			sun_v[pick] = new sun(sun_v[pick]->LEFT_DOWN_x, sun_v[pick]->LEFT_DOWN_y);
			sun_mod_v[pick] = 1;
		}

		for (int i = 0; i < 8; i++) {
			if (sun_mod_v[i] == 1) {
				sun_v[i]->print();
				sun_mod_v[i] = 0;
			}
		}

		
		check_inp(inp);
		conOut(9, 10) << "resurces: "; cout << resources; cout << "  ";

		for (int i = 0; i < 8; i++) {
			if (sun_mod_v[i] == 1) {
				sun_v[i]->clear();
				sun_mod_v[i] = 0;
			}
		}

		conOut(first_y - 5, first_x - 20) << "Sunflower"; cout << Sunflowe_nr<<"  ";
		conOut(first_y - 3, first_x - 20) << "score: "; cout << score<<"   ";
	}
};

