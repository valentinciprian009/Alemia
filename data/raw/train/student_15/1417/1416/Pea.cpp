#include "Pea.h"
#include "GameManager.h"

Arena::Pea::Pea(GameManager* pr, UserInterface::ConsoleOutput conout,  int y, int x) : ITickable(50), IGameElement(pr, conout)
{
	act = false;
	gx = x;
	gy = y;
	cx = VLINE + CELLX * (gx + 1) + 2;
	cy = HLINE + 3 + CELLY * gy;
}

Arena::Pea::~Pea()
{
	conOut(cy, cx - 1) << "  ";
}

void Arena::Pea::update()
{
	for (auto z : parent->zombies[gy])
		if (z->cx < cx + 2)
		{
			affectZombie(z);
			act = false;
			return;
		}
	act = cx < conOut.width()-5;
	updateTime();
}

void Arena::Pea::draw()
{
	conOut(cy, cx-2) << " -o";
}

bool Arena::Pea::active()
{
	return act;
}

void Arena::Pea::tickAction()
{
	cx++;
}

void Arena::Pea::affectZombie(BasicZombie* z)
{
	z->damage(1);
}
