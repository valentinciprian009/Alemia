#include "GameActions.h"
#include <stdlib.h>
#include <time.h>
#include "Sun.h"
#include "Game.h"

int GameActions::sunCounter = 30000;
int GameActions::zombieCounter = 50000;

void GameActions::doAction()
{

	srand(time(nullptr));
	int actionValue = rand() % 2;

	switch (actionValue)
	{
	case 0:
	{
		sunCounter--;
		if (sunCounter == 0)
		{
			sunCounter = 30000;
			Game::getGameInstance().addSun();
		}
		break;
	}
	case 1:
	{
		zombieCounter--;
		if (zombieCounter == 0)
		{
			zombieCounter = 50000;
			Game::getGameInstance().addZombie(rand() % 2);
		}
		break;
	}
	}
	Map::getInstance().runFlowersEffects();
}
