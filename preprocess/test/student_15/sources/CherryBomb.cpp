#include "CherryBomb.h"
#include "Constants.h"
#include "GameManager.h"

Arena::CherryBomb::CherryBomb(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x)
	: ITimer(CHERRYTIMER), BasicPlant(pr, conout, 3, y, x)
{

}

void Arena::CherryBomb::update()
{
	updateTime();
}

bool Arena::CherryBomb::active()
{
	return hp > 0 && !timerDone();
}

void Arena::CherryBomb::timerAction()
{
	for (auto it : parent->zombies[y])
		if (it->insideCell(x))
			it->damage(2);

	int miny = y > 0 ? y - 1 : 0;
	int maxy = y < TERENY - 1 ? y + 1 : TERENY - 1;

	for (int i = miny; i <= maxy; i++)
		for(int j = x-1; j<=x+1; j++)
			for (auto it : parent->zombies[i])
				if (it->insideCell(j))
					it->damage(2);
}
