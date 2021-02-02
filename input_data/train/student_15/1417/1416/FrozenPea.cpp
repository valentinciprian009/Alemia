#include "FrozenPea.h"
#include "Zombie.h"

void Arena::FrozenPea::affectZombie(BasicZombie* z)
{
	z->damage(1);
	z->slowDown();
}

Arena::FrozenPea::FrozenPea(GameManager* pr, UserInterface::ConsoleOutput conout, int y0, int x0)
	: Pea(pr, conout, y0, x0)
{
}


