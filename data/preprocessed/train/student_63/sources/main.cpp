#include <iostream>
#include <time.h>
#include <string>
#include "Log.h"
#include "COut.h"
#include "Entity.h"
#include "Lifeform.h"
#include "Zombie.h"
#include "Sun.h"
#include "Grid.h"
#include "Plant.h"
#include "Peashoter.h"
#include "Sunflower.h"
#include "MouseHandler.h"

int main()
{
	
	int gamecurrency = 0;
	COORD A;
	A.X = 5;
	A.Y = 15;
	std::string l1="												";
	std::string l2="               Poo vs. Zombies					";
	std::string l3 ="												";
	std::string l4="		 Loading game...					";
	std::vector<std::string>l5;
	l5.push_back(l1);
	l5.push_back(l2);
	l5.push_back(l3);
	l5.push_back(l4);
	for (std::vector<std::string>::iterator i = l5.begin(); i != l5.end(); *i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)2 * A.X,A.Y });
		std::cout << *i;
		A.Y++;

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Sleep(3000);
	system("cls");
	srand(time(NULL));
	
	Log logy;
	logy.user();
	MouseHandler  &mouseHandler = MouseHandler::getInstance();
	ConsoleHandler& out = ConsoleHandler::getInstance();
	std::list<Entity*> entities;
	//entities.push_back(new Zombie('Z', 110, 22, 4, 4, 23, 32));
	entities.push_back(new Peashoter('P', 13, 22, 2, 23));
	entities.push_back(new Peashoter('P', 13, 27, 2, 23));
	entities.push_back(new Peashoter('P', 13, 32, 2, 23));
	entities.push_back(new Peashoter('P', 13, 17, 2, 23));
	entities.push_back(new Peashoter('P', 13, 12, 2, 23));
	//entities.push_back(new Zombie('Z', 110, 27, 4, 4, 23, 32));
	//entities.push_back(new Zombie('Z', 110, 32, 4, 4, 23, 32));
	//entities.push_back(new Zombie('Z', 110, 17, 4, 4, 23, 32));
	//entities.push_back(new Zombie('Z', 110, 12, 4, 4, 23, 32));
	
	std::list<Entity*>::iterator prev;
	while (true)
	{
		for (int j = 0; j < 1000; j++) {

			if (j % 10==0) {
				entities.push_back(new Zombie('Z', 110, rand() % 5 * 5 + 12, 4, 4, 23, 32));
			}
			if (j % 100 == 0)
			{
				entities.push_back(new Sun(gamecurrency, 'X', rand() % 9*11 + 16, 5, 5));
			}
			mouseHandler.processInput();
			out(0, 0) << gamecurrency;
			Grid G(15, 10);
			G.print_cage();
			for (auto i = entities.begin(); i != entities.end();)
			{
				prev = i++;
				(*prev)->update();
				if ((*prev)->is_finish())
				{
					entities.remove(*prev);
				}
			}
			Sleep(100);
		}
		
	}

	std::cin.get();
	

}
