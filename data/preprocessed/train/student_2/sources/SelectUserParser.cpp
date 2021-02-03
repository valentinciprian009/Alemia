#include "SelectUserParser.h"
#include "Game.h"
void SelectUserParser::parseAction(std::string action)
{
	Game& game = Game::getGameInstance();
	if ((action.length() == 1) && (isdigit(action[0])))
	{
		int option = atoi(action.c_str());
		if (game.getUsersNum() + 1 == option)
		{
			game.changeGameState(Game::State::MainMenu);
			return;
		}
		game.changeUser(option);
	}
}
