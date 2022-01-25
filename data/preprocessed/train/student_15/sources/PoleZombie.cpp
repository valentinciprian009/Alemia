#include "PoleZombie.h"
#include "Constants.h"
#include "GameManager.h"

void Arena::PoleZombie::tickAction()
{
	int prv = int(gx - 2 / float(CELLX));
	if (parent->empty(gy, prv))
	{
		cx--;
		gx -= 1 / float(CELLX);
		if (gx < 2 / float(CELLX))
			parent->gameOver();
	}
	else if (jumped)
		parent->plants[gy][prv]->damage();
	else {
		cx -= CELLX + 5;
		gx -= float(CELLX + 5) / float(CELLX);
	}
}

Arena::PoleZombie::PoleZombie(GameManager* pr, UserInterface::ConsoleOutput conout, int y, bool superzombie)
	: BasicZombie(pr, conOut, y, superzombie ? 3 : 2), jumped(false)
{
}
