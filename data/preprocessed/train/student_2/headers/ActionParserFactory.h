#pragma once
#include "IParser.h"
#include "Game.h"
class ActionParserFactory
{
public:
	static IParser* generateParser(Game::State gameState);
};

