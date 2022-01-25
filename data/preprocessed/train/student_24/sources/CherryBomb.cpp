#include "CherryBomb.h"
#include "Game.h"

CherryBomb::CherryBomb(int x, int y, int pret) :
	Plant(x, y, 50, pret),
	BattleEntity(x, y, 50),
	Entity(x, y) {}

void CherryBomb::print() const
{
	const char coditaStanga = '/';
	const char coditaDreapta = '\\';
	const char cireasa = 153;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(10);
	conOut(coordX, coordY) << coditaStanga;
	conOut(coordX, coordY + 1) << coditaDreapta;
	conOut(coordX + 1, coordY - 1) << coditaStanga;
	conOut(coordX + 1, coordY + 2) << coditaDreapta;
	conOut.setColor(12);
	conOut(coordX + 2, coordY - 2) << cireasa;
	conOut(coordX + 2, coordY + 3) << cireasa;
}

void CherryBomb::action()
{
	Sleep(1000);
	ContainerRectangle<iBattleEntity*>* middle = Game::getBattleZone()->getNextRectangle(this->coordX, this->coordY);
	ContainerRectangle<iBattleEntity*>* up = Game::getBattleZone()->getUpRectangle(coordX, coordY);
	ContainerRectangle<iBattleEntity*>* down = Game::getBattleZone()->getDownRectangle(coordX, coordY);
	printExplosion();
	Sleep(1000);

	if (middle->getInterEntity() != nullptr)
	{
		if (dynamic_cast<iZombie*>(middle->getInterEntity()) != nullptr)
		{
			middle->getInterEntity()->setHealth(0);
			Game::addToScore(100);
		}
	}

	if (up != nullptr)
	{
		if (dynamic_cast<iZombie*>(up->getInterEntity()) != nullptr)
		{
			up->getInterEntity()->setHealth(0);
			Game::addToScore(100);
		}
	}
	if (down != nullptr)
	{
		if (dynamic_cast<iZombie*>(down->getInterEntity()) != nullptr)
		{
			down->getInterEntity()->setHealth(0);
			Game::addToScore(100);
		}
	}
	this->setHealth(0);
}

void CherryBomb::printExplosion() const
{
	const char coditaStanga = '/';
	const char coditaDreapta = '\\';
	const char cireasa = 153;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(196);
	conOut(coordX, coordY) << coditaStanga;
	conOut(coordX, coordY + 1) << coditaDreapta;
	conOut(coordX + 1, coordY - 1) << coditaStanga;
	conOut(coordX + 1, coordY + 2) << coditaDreapta;
	conOut.setColor(12);
	conOut(coordX + 2, coordY - 2) << cireasa;
	conOut(coordX + 2, coordY + 3) << cireasa;
}

CherryBomb::~CherryBomb()
{
	this->colors.clear();
}

iPlant* CherryBomb::clone()
{
	return new CherryBomb(*this);
}


