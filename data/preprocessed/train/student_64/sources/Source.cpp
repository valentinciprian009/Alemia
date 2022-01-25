#include "Game.h"
#include<conio.h>
#include <chrono>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"


using namespace std::chrono;

UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

int main(void)
{
	
		Game currentGame;
		auto begin = std::chrono::system_clock::now();
		auto end = std::chrono::system_clock::now();
		currentGame.Loading();
		currentGame.ShowMenu();
		currentGame.BuildTerrain();
		//currentGame.MoveZombie();

		while (true)
		{
			end = std::chrono::system_clock::now();
			if (std::chrono::duration_cast<seconds>(end - begin).count() > 2)
			{
				begin = std::chrono::system_clock::now();
				currentGame.SpawnSuns();
			}
			std::string action = conIn.getUserActions();
			if (action != "")
			{
				conOut(41, 2) << action;
			}
			currentGame.CheckSun(action);
			currentGame.CheckPlant(action);
			currentGame.StorePlant(action);
			currentGame.Move();
		}


	_getch();
	return 0;
}
