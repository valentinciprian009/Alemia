#include "computerActionFactory.h"
#include "DummyAction.h"
#include "GameActions.h"
IComputerAction* computerActionFactory::generateParser(Game::State gameState)
{
	switch (gameState)
	{
	case Game::State::Playing:
	{
		return new GameActions;
		break;
	}
	default:
		return new DummyAction;
		break;
	}
}
