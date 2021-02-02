#pragma once
#include "IComputerAction.h"
#include "Game.h"
class computerActionFactory
{
public:
	static IComputerAction* generateParser(Game::State gameState);
};

