#include "Game.h"
#include <conio.h>



int main(void)
{
	Game game = Game::getInstance();
	game.init();
	while (!game.is_finished())
	{
		game.play();
	}

	_getch();
	return 0;
}

