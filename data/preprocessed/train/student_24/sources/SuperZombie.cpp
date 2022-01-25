#include "SuperZombie.h"
#include "Game.h"

void SuperZombie::print() const
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	Zombie::print();
	conOut.setColor(12);
	conOut(coordX, coordY) << char(233);
}

void SuperZombie::action()
{
	if (((Game::getIteration() + 1) % 150) != 0)
		return;

	auto prev = Game::getBattleZone()->getPrevRectangle(coordX, coordY);
	auto current = Game::getBattleZone()->getRectangle(coordX, coordY);

	if (dynamic_cast<iPlant*>(prev->getInterEntity()) != nullptr)
		//daca as fi facut mecanismul acesta cu functii virtuale, 
		//plantele si zombie se puteau lovi intre ele si tot asta ajungeam sa fac
	{
		if (plantsEncountered == 0)
		{
			auto prevPrev = Game::getBattleZone()->getPrevRectangle(prev->getInterEntity()->getX(), prev->getInterEntity()->getY());
			Game::getBattleZone()->getRectangle(coordX, coordY)->erase();

			iZombie* toAdd = new SuperZombie(this->coordX, this->coordY, this->m_Health, this->m_Step, 1);
			toAdd->setX(prevPrev->getX() + 1);
			toAdd->setY(prevPrev->getY() + 4);

			delete current->getInterEntity();
			current->addEntity(nullptr);

			prevPrev->addEntity(toAdd);
		}
		prev->getInterEntity()->setHealth(prev->getInterEntity()->getHealth() - 10);
	}
	else
	{
		Game::getBattleZone()->getRectangle(coordX, coordY)->erase();

		iZombie* toAdd = new SuperZombie(this->coordX, this->coordY, this->m_Health, this->m_Step, plantsEncountered + 1);
		toAdd->setX(prev->getX() + 1);
		toAdd->setY(prev->getY() + 4);

		delete current->getInterEntity();
		current->addEntity(nullptr);

		prev->addEntity(toAdd);
	}
}

SuperZombie::SuperZombie(int x, int y, int health, int step, int plantsEncountered) : Entity(x, y), BattleEntity(x, y, health), movingEntity(x, y, step), Zombie(x, y, health, step), plantsEncountered(0)
{
	this->colors.push_back(12);
}

SuperZombie::~SuperZombie()
{
	colors.clear();
}
