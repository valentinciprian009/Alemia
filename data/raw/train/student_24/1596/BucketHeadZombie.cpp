#include "BucketHeadZombie.h"
#include "Game.h"
#include "ConsoleOutput.h"

void BucketHeadZombie::print() const
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	Zombie::print();
	conOut(coordX, coordY) << char(178);
}

void BucketHeadZombie::action()
{
	if (((Game::getIteration() + 1) % 150) != 0)
		return;

	auto prev = Game::getBattleZone()->getPrevRectangle(coordX, coordY);
	auto current = Game::getBattleZone()->getRectangle(coordX, coordY);

	if (dynamic_cast<iPlant*>(prev->getInterEntity()) != nullptr)
		//daca as fi facut mecanismul acesta cu functii virtuale, 
		//plantele si zombie se puteau lovi intre ele si tot asta ajungeam sa fac
	{
		prev->getInterEntity()->setHealth(prev->getInterEntity()->getHealth() - 10);
	}
	else
	{
		Game::getBattleZone()->getRectangle(coordX, coordY)->erase();

		iZombie* toAdd = new BucketHeadZombie(this->coordX, this->coordY, this->m_Health, this->m_Step);
		toAdd->setX(prev->getX() + 1);
		toAdd->setY(prev->getY() + 4);

		delete current->getInterEntity();
		current->addEntity(nullptr);

		prev->addEntity(toAdd);
	}
}

BucketHeadZombie::~BucketHeadZombie()
{
	this->colors.clear();
}

BucketHeadZombie::BucketHeadZombie(int x, int y, int health, int step) : Entity(x, y), BattleEntity(x, y, health), movingEntity(x, y, step), Zombie(x, y, health, step) {}