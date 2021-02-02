#include "Zombie.h"
#include "Game.h"

Zombie::Zombie(int x, int y, int health, int step) : Entity(x, y), BattleEntity(x, y, health), movingEntity(x, y, step)
{
	colors.push_back(8);
}

Zombie::~Zombie() { colors.clear(); }

void Zombie::print() const
{
	const char cap = char(233);
	const char corp = char(157);
	const char picioare = char(142);
	const char manaStanga = char(192);
	const char manaDreapta = char(191);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	
	conOut.setColor(*colors.begin());
	conOut(coordX, coordY) << cap;
	conOut(coordX + 1, coordY) << corp;
	conOut(coordX + 2, coordY) << picioare;
	conOut(coordX + 1, coordY - 1) << manaStanga;
	conOut(coordX + 1, coordY + 1) << manaDreapta;
}

void Zombie::action()
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

		iZombie* toAdd = new Zombie(this->coordX, this->coordY, this->m_Health, this->m_Step);
		toAdd->setX(prev->getX() + 1);
		toAdd->setY(prev->getY() + 4);

		delete current->getInterEntity();
		current->addEntity(nullptr);
		
		prev->addEntity(toAdd);
	}
}