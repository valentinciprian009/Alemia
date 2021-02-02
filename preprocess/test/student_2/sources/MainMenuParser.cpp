#include "MainMenuParser.h"
#include "Game.h"
void MainMenuParser::parseAction(std::string action)
{
	Game &instance = Game::getGameInstance();
	if (action == "1")
	{
		instance.changeGameState(Game::State::NewUser);
	}
	else if (action == "2")
	{
		instance.changeGameState(Game::State::SelectUser);
	}
	else if (action == "3")
	{
		instance.changeGameState(Game::State::Playing);
	}
	else if (action == "4")
	{
		exit(0);
	}
	else
	{
		return;
	}
}
