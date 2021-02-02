#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <iostream>
#include <chrono>
#include "mouse_input.h"
#include "Plants.h"
#include <vector>


class Plant_choosing_area
{
	private:
		UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
		int first_x;
		int first_y;
		vector<std::chrono::system_clock::time_point> begin;
		vector<std::chrono::system_clock::time_point> end;
		vector<int> RDY;

	public:
		entity* picked;

	Plant_choosing_area(int x, int y){
		first_x = x;
		first_y = y;
		picked = new entity(x ,y + 22);
		picked->print();
		entity* a = new Peashooter(x, y); a->print(); delete a;
		a = new Sunflower(x, y + 4); a->print(); delete a;
		a = new chery_bomb(x, y + 8); a->print(); delete a;
		a = new wall_nut(x, y + 12); a->print(); delete a;
		a = new snow_pea(x, y + 16); a->print(); delete a;

		auto  time = std::chrono::system_clock::now();

		for (int i = 0; i < 5; i++) {
			begin.push_back(time);
			end.push_back(time);
			RDY.push_back(0);
		}
	}


	void run(mouse_input inp,int& resources){
		check_mouse_input(inp, resources);
		check_time();
	}

	void check_mouse_input(mouse_input inp , int &resouces)
	{
		if ((inp.x != 0) && (inp.y != 0))
		{
			if ((inp.x >= first_x) && (inp.x <= first_x + 10))
			{
				if ((inp.y <= first_y) && (inp.y > first_y-4)) {
					if ((RDY[0]==1)&&(resouces-Peashooter::cost>=0)) {
						begin[0] = std::chrono::system_clock::now();
						picked = new Peashooter(first_x, first_y + 22);
						picked->clear();
						picked->print();
						RDY[0] = 0;
						resouces = resouces - Peashooter::cost;
					}
				}
				else if ((inp.y <= first_y+4) && (inp.y > first_y)) {
					if ((RDY[1] == 1)&&(resouces-Sunflower::cost>=0)) {
						begin[1] = std::chrono::system_clock::now();
						picked = new Sunflower(first_x, first_y + 22);
						picked->clear();
						picked->print();
						RDY[1] = 0;
						resouces = resouces - Sunflower::cost;
					}
				}
				else if ((inp.y <= first_y + 8) && (inp.y > first_y)+4) {
					if ((RDY[2] == 1) && (resouces -chery_bomb::cost >= 0)) {
						begin[2] = std::chrono::system_clock::now();
						picked = new chery_bomb(first_x, first_y + 22);
						picked->clear();
						picked->print();
						RDY[2] = 0;
						resouces = resouces - chery_bomb::cost;
					}
				}
				else if ((inp.y <= first_y + 12) && (inp.y > first_y+8)) {
					if ((RDY[3] == 1) && (resouces - wall_nut::cost >= 0)) {
						begin[3] = std::chrono::system_clock::now();
						picked = new wall_nut(first_x, first_y + 22);
						picked->clear();
						picked->print();
						RDY[3] = 0;
						resouces = resouces - wall_nut::cost;
					}
				}
				else if ((inp.y <= first_y + 16) && (inp.y > first_y+12)) {
					if ((RDY[4] == 1) && (resouces - snow_pea::cost >= 0)) {
						begin[4] = std::chrono::system_clock::now();
						picked = new snow_pea(first_x, first_y + 22);
						picked->clear();
						picked->print();
						RDY[4] = 0;
						resouces = resouces - snow_pea::cost;
					}
				}
			}
		}
	}

	void check_time()
	{
		end[0] = std::chrono::system_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end[0] - begin[0]).count() < Peashooter::reuse_time) {
			conOut(first_y - 2, first_x - 10) << Peashooter::reuse_time-(std::chrono::duration_cast<std::chrono::seconds>(end[0] - begin[0]).count());
			std::cout << "          ";
		}
		else if (std::chrono::duration_cast<std::chrono::seconds>(end[0] - begin[0]).count() == Peashooter::reuse_time){
			conOut(first_y - 2, first_x - 10) << "READY";
			RDY[0] = 1;
		}

		end[1] = std::chrono::system_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end[1] - begin[1]).count() < Sunflower::reuse_time) {
			conOut(first_y +2, first_x - 10) << Sunflower::reuse_time-(std::chrono::duration_cast<std::chrono::seconds>(end[1] - begin[1]).count());
			std::cout << "          ";
		}
		else if (std::chrono::duration_cast<std::chrono::seconds>(end[1] - begin[1]).count() == Sunflower::reuse_time) {
			conOut(first_y + 2, first_x - 10) << "READY";
			RDY[1] = 1;
		}

		end[2] = std::chrono::system_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end[2] - begin[2]).count() < chery_bomb::reuse_time) {
			conOut(first_y + 6, first_x - 10) << chery_bomb::reuse_time-(std::chrono::duration_cast<std::chrono::seconds>(end[2] - begin[2]).count());
			std::cout << "          ";
			
		}
		else if (std::chrono::duration_cast<std::chrono::seconds>(end[2] - begin[2]).count() == chery_bomb::reuse_time) {
			conOut(first_y + 6, first_x - 10) << "READY";
			RDY[2] = 1;
		}

		end[3] = std::chrono::system_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end[3] - begin[3]).count() < wall_nut::reuse_time) {
			conOut(first_y + 10, first_x - 10) << wall_nut::reuse_time-(std::chrono::duration_cast<std::chrono::seconds>(end[3] - begin[3]).count());
			std::cout << "          ";
		}
		else if (std::chrono::duration_cast<std::chrono::seconds>(end[3] - begin[3]).count() == wall_nut::reuse_time) {
			conOut(first_y + 10, first_x - 10) << "READY";
			RDY[3] = 1;
		}

		end[4] = std::chrono::system_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(end[4] - begin[4]).count() < snow_pea::reuse_time) {
			conOut(first_y + 14, first_x - 10) << snow_pea::reuse_time-(std::chrono::duration_cast<std::chrono::seconds>(end[4] - begin[4]).count());
			std::cout << "          ";
		}
		else if (std::chrono::duration_cast<std::chrono::seconds>(end[4] - begin[4]).count() == snow_pea::reuse_time) {
			conOut(first_y + 14, first_x - 10) << "READY";
			RDY[4] = 1;
		}
	}
};

