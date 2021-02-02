#include "Game.h"
#include <iostream>
#include "Sun.h"

int main(void)
{
	Game &game = Game::getGameInstance();
	game.run();
}

