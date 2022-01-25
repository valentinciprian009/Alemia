#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <conio.h>
#include <random>
#include <time.h>
#include <chrono>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "Scoreboard.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

Game::Game()
{
	for (int i = 0; i < 20; i++)
	{
		begin[i] = std::chrono::system_clock::now();
		end[i] = std::chrono::system_clock::now();
	}
}


Game::~Game()
{
}

void  Game::doLoadingBar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		UserInterface::ConsoleOutput::getInstance()(ROW_TITLE + 1, col) << printedChar;
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
}

void Game::Loading()
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	UserInterface::ConsoleOutput::getInstance()(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";

	auto begin = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	while (std::chrono::duration_cast<seconds>(end - begin).count() < 3)
	{
		end = std::chrono::system_clock::now();
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			UserInterface::ConsoleOutput::getInstance()(41, 2) << action;
		}
		
	}

	system("CLS");
	SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void Game::ShowMenu()
{
	Menu menu;
	menu.PrintAnimation();
	user = menu.AskUserInput();
}

void Game::BuildTerrain()
{
	terrain.init();

}


void Game::SpawnSuns()

{
		int value = rand() % 8;
			terrain.suns[value].setEntity(Entities::Sun);
			terrain.suns[value].ChangeInteriorValue();
}

void Game::CheckSun(std::string action)
{
	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conin = UserInterface::ConsoleInput::getInstance();

	std::string x, y;

	if (action.find("double")!=std::string::npos)
	{
		for (auto i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (auto i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int _m_x, _m_y;
		_m_x = stoi(x);
		_m_y = stoi(y);

		for (int i = 0; i <= 7; i++)
		{
			if((_m_x >= terrain.suns[i].getLeftCorner().get_y() && _m_x <= terrain.suns[i].getLeftCorner().get_y() + 6) &&
				_m_y >= terrain.suns[i].getLeftCorner().get_x() && _m_y <= terrain.suns[i].getLeftCorner().get_x() + 5 &&
				terrain.suns[i].getEntity() == Entities::Sun)
			{
				terrain.suns[i].setEntity(Entities::NoEntity);
				terrain.suns[i].ChangeInteriorValue();
				terrain.scoreBoard.points += 50;
				terrain.PrintScore();
				break;
			}
		}
	}
	
}

void Game::CheckPlant(std::string action)
{
	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conin = UserInterface::ConsoleInput::getInstance();

	std::string x, y;

	if (action.find("double") != std::string::npos)
	{
		for (auto i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (auto i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int _m_x, _m_y;
		_m_x = stoi(x);
		_m_y = stoi(y);

		for (int i = 0; i < 5; i++)
		{
			if ((_m_x >= terrain.plants[i].getLeftCorner().get_y() && _m_x <= terrain.plants[i].getLeftCorner().get_y() + 6) &&
				_m_y >= terrain.plants[i].getLeftCorner().get_x() && _m_y <= terrain.plants[i].getLeftCorner().get_x() + 5 &&
				terrain.plants[i].getEntity() == Entities::Plant)
			{
				if (terrain.scoreBoard.points >= 50 && selected_plant==PlantTypes::NoPlant)
				{
					selected_plant = terrain.plants[i].plant_type;
					terrain.scoreBoard.points -= 50;
					terrain.PrintScore();
				}
			}
		}
	}

}

void Game::StorePlant(std::string action)
{

	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conin = UserInterface::ConsoleInput::getInstance();

	std::string x, y;

	if (action.find("double") != std::string::npos)
	{
		for (auto i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (auto i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int _m_x, _m_y;
		_m_x = stoi(x);
		_m_y = stoi(y);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((_m_x >= terrain.mainZone[i][j].getLeftCorner().get_y() && _m_x <= terrain.mainZone[i][j].getLeftCorner().get_y() + 6))
				{
					if (_m_y >= terrain.mainZone[i][j].getLeftCorner().get_x() && _m_y <= terrain.mainZone[i][j].getLeftCorner().get_x() + 5)
					{
						if (terrain.mainZone[i][j].getEntity() == Entities::NoEntity)
						{
							
								terrain.mainZone[i][j].setEntity(Entities::Plant);
								terrain.mainZone[i][j].plant_type = selected_plant;
								selected_plant = PlantTypes::NoPlant;
								terrain.mainZone[i][j].ChangeInteriorValue();
								projectile.push_back(Projectiles(terrain.mainZone[i][j].getLeftCorner().get_y(), terrain.mainZone[i][j].getLeftCorner().get_x()));
						}
					}
				}
			}
		}

	}
}

void Game::Move()
{
	int k = 0;
	for (auto it = projectile.begin(); it != projectile.end(); it++)
	{
		it->Move(end[k], begin[k]);
		k++;
	}

}




