#include "ActionParserFactory.h"
#include "DefeatMenuParser.h"
#include "VictoryMenuParser.h"
#include "MainMenuParser.h"
#include "NewUserParser.h"
#include "PlayingParser.h"
#include "SelectUserParser.h"
class
	IParser* ActionParserFactory::generateParser(Game::State gameState)
{
	switch (gameState)
	{
	case Game::State::MainMenu:
	{
		return new MainMenuParser;
		break;
	}
	case Game::State::NewUser:
	{
		return new NewUserParser;
		break;
	}
	case Game::State::SelectUser:
	{
		return new SelectUserParser;
		break;
	}
	case Game::State::Playing:
	{
		return new PlayingParser;
		break;
	}
	case Game::State::Defeat:
	{
		return new DefeatMenuParser;
		break;
	}
	case Game::State::Victory:
	{
		return new VictoryMenuParser;
		break;
	}

	}
	return nullptr;
}
