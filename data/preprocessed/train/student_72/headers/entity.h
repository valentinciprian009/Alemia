#pragma once
#include "Entity_Interface.h"
#include "ConsoleOutput.h"
#include <vector>
#include <chrono>

class entity :public Entity_Interface
{

	public:
		UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
		std::string  name;
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;
		int LEFT_DOWN_x;
		int LEFT_DOWN_y;
		int health = 0;
		int score = 0;

		entity(int x, int y) {
			name = "entity";
			LEFT_DOWN_x = x;
			LEFT_DOWN_y = y;
		}

		 void clear(){
			conOut(LEFT_DOWN_y - 1, LEFT_DOWN_x+1) << "         ";
			conOut(LEFT_DOWN_y - 2, LEFT_DOWN_x+1) << "         ";
			conOut(LEFT_DOWN_y - 3, LEFT_DOWN_x+1) << "         ";
		}

		
		virtual void print() override{
			conOut(LEFT_DOWN_y, LEFT_DOWN_x)   << "----------";
			conOut(LEFT_DOWN_y-1, LEFT_DOWN_x) << "-";
			conOut(LEFT_DOWN_y-2, LEFT_DOWN_x) << "-";
			conOut(LEFT_DOWN_y-3, LEFT_DOWN_x) << "-";
			conOut(LEFT_DOWN_y-4, LEFT_DOWN_x) << "----------";
		}

		virtual void run(std::vector<entity*>& L, bool* L_mod,int i,int& sunflower_nr,int& score){}
};

