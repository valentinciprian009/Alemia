#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include "Entity.h"
#include "Shop.h"
#include "Resources.h"
#include "Score.h"
#include "Terrain.h"
#include <vector>
#include "Player.h"
#include "UsersList.h"
#include "Login.h"
#include "Log.h"
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now(), begin1 = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar;
	

	while (true)
	{
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
		auto end = steady_clock::now(), end1 = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > 150)
		{
			begin = end;
			conOut(ROW_TITLE + 1, col) << printedChar;
			if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
				if (printedChar == "*")
				{
					printedChar = " ";
				}
				else
				{
					printedChar = "*";
				}
				col = COL_FIRST_STAR_POSITION;
			}
			else
			{
				col += COL_DISTANCE_BETWEEN_STARS;
			}
		}
		if (duration_cast<milliseconds>(end1 - begin1).count() > 5000)
			break;
		std::cout.clear();
	}
}
void doLogin(Player* p)
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	Login* l = new Login();
	bool login_done = 0;
	while (true)
	{
		std::string action = conIn.getUserActions();
		if (!login_done && l)
		{
			login_done = l->return_tasting(action);
			l->draw();
			system("cls");
		}
		else
		{
			p = new Player(*l->get_player());
			break;
		}
	}
	delete l;
}
void clear()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 162; i++)
		for (int j = 0; j < 40; j++)
			conOut(i, j) << " ";
}
int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	Player p;
	UsersList users = UsersList::get_instance();
	doLoadingBar();
	doLogin(&p);
	users.add(p);
	Log::adaug_mesaj("s -a creat user");
	//clear();
	std::vector<Entity*> entities;
	entities.push_back(new Shop(10, 0));
	entities.push_back(new Resources(1, 16));
	Score* score = Score::get_instance(1, 0);
	entities.push_back(score);
	entities.push_back(new Terrain(10, 16));
	Log::adaug_mesaj("s -a inceput jocul");
	while (true)
	{
		for (auto it : entities)
		{
			it->draw();
		}
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(0, 0) << action;
		}
		for (auto it : entities)
		{
			it->update(action);
		}
	
		std::cout.clear();
	}
	UsersList::destroy_instance();
	Log::adaug_mesaj("s -a creat fisierul de logare");
	return 0;
}

