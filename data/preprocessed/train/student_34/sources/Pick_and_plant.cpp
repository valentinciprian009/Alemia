#define _CRT_SECURE_NO_WARNINGS
#include "Pick_and_plant.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "Pea.h"
#include "Terrain.h"
#include <chrono>
#include <thread>
#include <iterator>
using namespace std::chrono;



void Pick_and_plant::colision()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int aux1 = 0;

	if (duration_cast<milliseconds>(end - begin).count() > 100)
	{
		begin = end;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < nr_peashooters; j++) {
				if (zombies[i].get_y() == bullets[j].get_y() && zombies[i].get_x() == bullets[j].get_x())
				{
				
					k++;
					zombies[i].set_health(zombies[i].get_health() - 50);
					
				}
			}
		}
	
	}
}

Pick_and_plant::Pick_and_plant()
{
	zombies = new Zombie[5];
	aux = 0;
	nr_peashooters = 0;
	coins = 900;
	zombies[0].set_x(11);
	zombies[1].set_x(16);
	zombies[2].set_x(21);
	zombies[3].set_x(26);
	zombies[4].set_x(31);
	k = 0;
	zombies[0].set_y(137);
	zombies[1].set_y(137);
	zombies[2].set_y(137);
	zombies[3].set_y(137);
	zombies[4].set_y(137);
}

int Pick_and_plant::spawn()
{
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int aux1 = 0;
	
	if (duration_cast<milliseconds>(end - begin).count() > 300)
	{
		begin = end;
	
		for (int i = 0; i < 5; i++) {
			
			if (zombies[i].get_health() > 0) {
				zombies[i].draw(zombies[i].get_x(), zombies[i].get_y() - 2);
				
				if ((zombies[i].get_y() - 2) == 21)
					return 2;
				zombies[i].set_y(zombies[i].get_y() - 1);

			
				zombies[i].delete_(zombies[i].get_x(), zombies[i].get_y() + 1);
			
			
			}
			else {
				zombies[i].delete_(zombies[i].get_x(), zombies[i].get_y());
				zombies[i].delete_(zombies[i].get_x(), zombies[i].get_y()-1);
			}
		}

	}
}
void Pick_and_plant::shoot_peashooter() {
	Pea pea;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		static auto begin = steady_clock::now();
		auto end = steady_clock::now();
		int aux1=0;
	
		if (duration_cast<milliseconds>(end - begin).count() > 100)
		{
			
			begin = end;
			for (int i = 0; i < nr_peashooters; i++)
			{
				colision();
					pea.draw(bullets[i].get_x() + 1, bullets[i].get_y() + 3);
								conOut(bullets[i].get_x() + 1, bullets[i].get_y() + 2) << " ";
					aux1 = bullets[i].get_y() + 1;

					bullets[i].set_y(aux1);
					if (aux1 == 137) {
						bullets[i].set_y(first_pos[i]);
						conOut(bullets[i].get_x() + 1, 139) <<" ";
					}
			}
		}
		
	
}




void Pick_and_plant::peashooter(std::string action,Menu a,Terrain b)
{  
	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	
	if (6 <= atoi(a.get_x()) && atoi(a.get_x()) <= 12 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14)
	{
	
		while (true)
		{
			shoot_peashooter();
			spawn();
			int aux = 0;
			std::string action1 = ConIn.getUserActions();

			a.coordonate(action1);
			for (int i = 0; i <= 7; i++) {
				if (line1(action1, a) == i && b.get_lv()==3)
				{
					if (coins >= 100 && check_position(i)!=0)
					{
						coins = coins - 100;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						p.draw(11, 26 + i * 15);
						bullets[nr_peashooters].set_x(11);
						bullets[nr_peashooters].set_y(26+i*15);
						first_pos.push_back(26 + (i % 8) * 15);
						pozitii_ocupate.push_back(i);
						nr_peashooters++;
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 8; i <= 15; i++) {
				if (line2(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 100 && check_position(i) != 0)
					{
						coins = coins - 100;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						p.draw(16, 26 + (i%8) * 15);
						bullets[nr_peashooters].set_x(16);
						bullets[nr_peashooters].set_y(26 + (i%8) * 15);
						first_pos.push_back(26 + (i % 8) * 15);
						nr_peashooters++;
						
						pozitii_ocupate.push_back(i);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
					
				}
			}
			for (int i = 16; i <= 23; i++) {
				if (line3(action1, a) == i)
				{
					if (coins >= 100 && check_position(i) != 0)
					{
						coins = coins - 100;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						p.draw(21, 26 + (i % 8) * 15);
						bullets[nr_peashooters].set_x(21);
						bullets[nr_peashooters].set_y(26 + (i % 8) * 15);
						first_pos.push_back(26 + (i % 8) * 15);
						pozitii_ocupate.push_back(i);

						aux = 1;
						nr_peashooters++;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				
				}
			}
			for (int i = 24; i <= 31; i++) {
				if (line4(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 100 && check_position(i) != 0)
					{
						coins = coins - 100;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						bullets[nr_peashooters].set_x(26);
						bullets[nr_peashooters].set_y(26 + (i % 8) * 15);
						p.draw(26, 26 + (i % 8) * 15);
						first_pos.push_back(26 + (i % 8) * 15);
						aux = 1;
						nr_peashooters++;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}for (int i = 32; i <= 39; i++) {
				if (line5(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 100 && check_position(i) != 0)
					{
						coins = coins - 100;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						bullets[nr_peashooters].set_x(31);
						bullets[nr_peashooters].set_y(26 + (i % 8) * 15);
						p.draw(31, 26 + (i % 8) * 15);
						first_pos.push_back(26 + (i % 8) * 15);
						aux = 1;
						nr_peashooters++;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
					
				}
			}
			if (aux == 1) {
				
				conOut(38, 63) << "                     ";
				break;
			}
			
		}
	}
	
}

void Pick_and_plant::sunflower(std::string action, Menu a,Terrain b)
{
	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (6 <= atoi(a.get_x()) && atoi(a.get_x()) <= 12 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 18)
	{

		while (true)
		{
			spawn();
			shoot_peashooter();
			int aux = 0;
			std::string action1 = ConIn.getUserActions();

			a.coordonate(action1);
			for (int i = 0; i <= 7; i++) {
				if (line1(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						s.draw(11, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 8; i <= 15; i++) {
				if (line2(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						s.draw(16, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 16; i <= 23; i++) {
				if (line3(action1, a) == i)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						s.draw(21, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			for (int i = 24; i <= 31; i++) {
				if (line4(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						s.draw(26, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}for (int i = 32; i <= 39; i++) {
				if (line5(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						s.draw(31, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			if (aux == 1) {
				
				conOut(38, 63) << "                     ";
				break;
			}
		}
	}
}

void Pick_and_plant::cherrybomb(std::string action, Menu a,Terrain b)
{
	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (6 <= atoi(a.get_x()) && atoi(a.get_x()) <= 12 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 23)
	{

		while (true)
		{
			spawn();
			int aux = 0;
			std::string action1 = ConIn.getUserActions();
			shoot_peashooter();
			a.coordonate(action1);
			for (int i = 0; i <= 7; i++) {
				if (line1(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 150 && check_position(i)!=0)
					{
						coins = coins - 150;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						c.draw(11, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 8; i <= 15; i++) {
				if (line2(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 150 && check_position(i) != 0)
					{
						coins = coins - 150;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						c.draw(16, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 16; i <= 23; i++) {
				if (line3(action1, a) == i)
				{
					if (coins >= 150 && check_position(i) != 0)
					{
						coins = coins - 150;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						c.draw(21, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			for (int i = 24; i <= 31; i++) {
				if (line4(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 150 && check_position(i) != 0)
					{
						coins = coins - 150;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						c.draw(26, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}for (int i = 32; i <= 39; i++) {
				if (line5(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 150 && check_position(i) != 0)
					{
						coins = coins - 150;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						c.draw(31, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			if (aux == 1) {
				
				conOut(38, 63) << "                     ";
				break;
			}
		}
	}
}

void Pick_and_plant::snow_pea(std::string action, Menu a,Terrain b)
{
	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (6 <= atoi(a.get_x()) && atoi(a.get_x()) <= 12 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34)
	{

		while (true)
		{
			spawn();
			shoot_peashooter();
			int aux = 0;
			std::string action1 = ConIn.getUserActions();

			a.coordonate(action1);
			for (int i = 0; i <= 7; i++) {
				if (line1(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 175 && check_position(i) != 0)
					{
						coins = coins - 175;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						sp.draw(11, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 8; i <= 15; i++) {
				if (line2(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 175 && check_position(i) != 0)
					{
						coins = coins - 175;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						sp.draw(16, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 16; i <= 23; i++) {
				if (line3(action1, a) == i)
				{
					if (coins >= 175 && check_position(i) != 0)
					{
						coins = coins - 175;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						sp.draw(21, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 24; i <= 31; i++) {
				if (line4(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 175 && check_position(i) != 0)
					{
						coins = coins - 175;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						sp.draw(26, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}for (int i = 32; i <= 39; i++) {
				if (line5(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 175 && check_position(i) != 0)
					{
						coins = coins - 175;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						sp.draw(31, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			if (aux == 1) {
				
				conOut(38, 63) << "                     ";
				break;
			}
		}
	}
}

void Pick_and_plant::wallnut(std::string action, Menu a,Terrain b)
{
	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (6 <= atoi(a.get_x()) && atoi(a.get_x()) <= 12 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29)
	{

		while (true)
		{
			spawn();
			shoot_peashooter();
			int aux = 0;
			std::string action1 = ConIn.getUserActions();

			a.coordonate(action1);
			for (int i = 0; i <= 7; i++) {
				if (line1(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						
						w.draw(11, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 8; i <= 15; i++) {
				if (line2(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 50 && check_position(i) != 0 )
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						w.draw(16, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}
				}
			}
			for (int i = 16; i <= 23; i++) {
				if (line3(action1, a) == i)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						w.draw(21, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			for (int i = 24; i <= 31; i++) {
				if (line4(action1, a) == i && (b.get_lv() == 3 || b.get_lv() == 2))
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						w.draw(26, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}for (int i = 32; i <= 39; i++) {
				if (line5(action1, a) == i && b.get_lv() == 3)
				{
					if (coins >= 50 && check_position(i) != 0)
					{
						coins = coins - 50;
						conOut(3, 9) << "   ";
						conOut(3, 9) << coins;
						pozitii_ocupate.push_back(i);
						w.draw(31, 26 + (i % 8) * 15);
						aux = 1;
					}
					else {
						conOut(38, 63) << "Coins insuficienti";
						aux = 1;
					}

				}
			}
			if (aux == 1) {
			
				conOut(38, 63) << "                     ";
				break;
			}
		}
	}
}

int Pick_and_plant::sun_line(std::string action1, Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 0;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 1;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 2;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 3;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 4;
	}
	if (96 <= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 5;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 6;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 1 <= atoi(a.get_y()) && atoi(a.get_y()) <= 6) {
		if (strstr(action1.c_str(), "CLICK"))
			return 7;
	}

}









int Pick_and_plant::line1(std::string action1,Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK")) 
			return 0;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 1;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 2;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 3;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 4;
	}
	if (96<= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 5;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 6;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 11 <= atoi(a.get_y()) && atoi(a.get_y()) <= 14) {
		if (strstr(action1.c_str(), "CLICK"))
			return 7;
	}
}

int Pick_and_plant::line2(std::string action1, Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 8;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 9;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 10;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 11;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 12;
	}
	if (96 <= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 13;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 14;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 16 <= atoi(a.get_y()) && atoi(a.get_y()) <= 19) {
		if (strstr(action1.c_str(), "CLICK"))
			return 15;
	}
}

int Pick_and_plant::line3(std::string action1, Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 21<= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 16;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 17;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 18;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 19;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 20;
	}
	if (96 <= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 21;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <= 24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 22;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 21 <= atoi(a.get_y()) && atoi(a.get_y()) <=24) {
		if (strstr(action1.c_str(), "CLICK"))
			return 23;
	}
}

int Pick_and_plant::line4(std::string action1, Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 24;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 25;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 26;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 27;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 28;
	}
	if (96 <= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 29;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 30;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 26 <= atoi(a.get_y()) && atoi(a.get_y()) <= 29) {
		if (strstr(action1.c_str(), "CLICK"))
			return 31;
	}
}

int Pick_and_plant::line5(std::string action1, Menu a)
{
	if (21 <= atoi(a.get_x()) && atoi(a.get_x()) <= 34 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 32;
	}
	if (36 <= atoi(a.get_x()) && atoi(a.get_x()) <= 49 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 33;
	}
	if (51 <= atoi(a.get_x()) && atoi(a.get_x()) <= 64 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 34;
	}
	if (66 <= atoi(a.get_x()) && atoi(a.get_x()) <= 79 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 35;
	}
	if (81 <= atoi(a.get_x()) && atoi(a.get_x()) <= 94 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 36;
	}
	if (96 <= atoi(a.get_x()) && atoi(a.get_x()) <= 109 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 37;
	}
	if (111 <= atoi(a.get_x()) && atoi(a.get_x()) <= 124 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 38;
	}
	if (126 <= atoi(a.get_x()) && atoi(a.get_x()) <= 139 && 31 <= atoi(a.get_y()) && atoi(a.get_y()) <= 34) {
		if (strstr(action1.c_str(), "CLICK"))
			return 39;
	}
}

int  Pick_and_plant::check_position(int x)
{
	for (auto it = pozitii_ocupate.begin(); it != pozitii_ocupate.end(); it++)
		if (*it == x)
			return 0;

	return 1;
}


void Pick_and_plant::sun_coins(std::string action, Menu a)
{
	Sun sun;
	FILE *f = fopen("t.txt", "r");
	int x;
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i <= 7; i++) {
		fscanf(f, "%d", &x);
		rewind(f);
		if (sun_line(action, a) == i && x==i )
		{   
			coins += 25;

			conOut(3, 9) << "   ";
			conOut(3, 9) << coins;
			sun._delete_after();
		}
	}
	fclose(f);
}

Pick_and_plant::~Pick_and_plant()
{

}
