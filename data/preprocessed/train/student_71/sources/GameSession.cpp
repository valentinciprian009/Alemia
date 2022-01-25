#include "GameSession.h"
#include "Plant.h"
#include "Player.h"
#include "NormalZombie.h"
#include "Logger.h"
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>
#pragma comment(lib, "winmm.lib")

using namespace std::chrono;

GameSession* GameSession::instance = NULL;

char* loadSounds()
{
	size_t length;
	char* buffer;
	std::ifstream in("points.wav", std::ios::binary | std::ios::in);
	in.seekg(0, std::ios::end);
	length = in.tellg();
	in.seekg(0, std::ios::beg);
	buffer = new char[length];
	in.read(buffer, length);

	return buffer;
}

char* loadSound()
{
	size_t length;
	char* buffer;
	std::ifstream in("plant.wav", std::ios::binary | std::ios::in);
	in.seekg(0, std::ios::end);
	length = in.tellg();
	in.seekg(0, std::ios::beg);
	buffer = new char[length];
	in.read(buffer, length);

	return buffer;
}

GameSession::GameSession()
{
}

GameSession::~GameSession()
{
	terrain.destroyInstance();
	sun.destroyInstance();
	items.destroyInstance();
	scoreboard.destroyInstance();
}

GameSession& GameSession::getInstance()
{
	if (!instance)
		instance = new GameSession;
	return *instance;
}

void GameSession::destroyInstance()
{
	delete instance;
}


void GameSession::execute()
{
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	std::string action;
	int row;
	int col;

	char* sunClick = loadSounds();
	char* plant = loadSound();
	char* p;

	static auto sun_timer = steady_clock::now();
	static auto zombie_timer = steady_clock::now();


	player.increaseScore(1000);

	while (true)
	{
		if (scoreboard.win())
			this->terminate(0);

		terrain.execute();
		auto end = steady_clock::now();
		if (duration_cast<seconds>(end - sun_timer).count() >= sunSpawnRate)
		{
			sun_timer = end;
			sun.spawnSun();
		}
		if (duration_cast<seconds>(end - zombie_timer).count() >= zombieSpawnRate)
		{
			zombie_timer = end;
			if(scoreboard.getRemainingZombies())
				terrain.spawnZombie();
		}


		action = conIn.getUserActions();
		if ((action != "") && (p = (char*)strstr(action.c_str(), "mouse clicked at")))
		{
			
			char* temp = strtok((char*)action.c_str(), "(,)");
			col = atoi(strtok(NULL, "(,)"));
			row = atoi(strtok(NULL, "(,)"));

			if (col >= 20)
			{
				col = (col - 20) / 15;
				if (row <= 5)
					if (sun.isSun(col))
					{
						PlaySound(sunClick, NULL, SND_MEMORY | SND_ASYNC);
						sun.clearSlot(col);
						player.increaseScore(25);
						selectedItem = "";
						scoreboard.update();
					}
				if ((row >= 9) && (row <= 38))
				{
					row = (row - 9) / 6;
					if ((selectedItem != "") && (terrain.isEmpty(row, col))&&(player.getAvailableSun()>=items.item[row]->getPrice()))
					{
						if (terrain.place(selectedItem, row, col))
						{
							PlaySound(plant, NULL, SND_MEMORY | SND_ASYNC);
							player.decreaseScore(items.item[row]->getPrice());
							scoreboard.update();
						}
					}
					selectedItem = "";
				}
			}

			if ((col >= 3) && (col <= 17))
				if ((row >= 10) && (row <= 37))
				{
					row = (row - 10) / 6;
					if (items.identity(row) == selectedItem)
						selectedItem = "";
					selectedItem = items.identity(row);
				}

		}
	}
}

void GameSession::terminate(int code)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	system("cls");
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	if (code == -1)
		conOut(20, 60, 1) << "You lost the game.";
	else
	{
		conOut(20, 60, 1) << "You won the game.";
		Player& player = Player::getInstance();
		if (player.getCurrentLevel() > player.getMaximumLevel())
			player.increaseLevel();
	}
	Sleep(3000);
	this->destroyInstance();
}


