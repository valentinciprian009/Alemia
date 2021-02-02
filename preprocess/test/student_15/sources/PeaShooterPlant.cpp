#include "PeaShooterPlant.h"
#include "GameManager.h"
#include "FrozenPea.h"

Arena::PeaShooter::PeaShooter(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x, bool frozen) : 
	ITickable(PEASHOOTERP), BasicPlant(pr, conout, frozen ? 4 : 0, y, x) 
{
}

void Arena::PeaShooter::update()
{
	updateTime();
}

void Arena::PeaShooter::tickAction()
{
	if(id == 0)
		parent->peas[y].push_back(new Pea(parent, conOut, y, x));
	else
		parent->peas[y].push_back(new FrozenPea(parent, conOut, y, x));
}
