#include "SnowPea.h"
#include "Game.h"
#include <Windows.h>

SnowPea::SnowPea(int x, int y, Projectile* proiectil, int pret) :
	Entity(x, y),
	Plant(x, y, 50, pret),
	BattleEntity(x, y, 50),
	PlantShooter(x, y, 50, 2, proiectil, pret) {}

SnowPea::SnowPea(const SnowPea& old) :
	Entity(old.coordX, old.coordY),
	BattleEntity(old.coordX, old.coordY, old.m_Health),
	Plant(old.coordX, old.coordY, old.m_Health, old.m_Price),
	PlantShooter(old.coordX, old.coordY, old.m_Health, 5, nullptr, 200)
{
	this->m_Proiectil = new FrozenPea(old.coordX, old.coordY);
}

iPlant* SnowPea::clone()
{
	return new SnowPea(*this);
}

SnowPea::~SnowPea()
{
	this->colors.clear();
	delete m_Proiectil;
}

void SnowPea::print() const
{
	const char head = 153;
	const char mouth = 167;
	const char body = 198;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(10);
	conOut(coordX, coordY) << head;
	conOut(coordX + 1, coordY) << body;

	conOut.setColor(11);
	conOut(coordX, coordY + 1) << mouth;
	
}

void SnowPea::action()
{
	if ((Game::getIteration() % 10) != 0)
		return;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	iBattleEntity* current = Game::getBattleZone()->getRectangle(m_Proiectil->getX(), m_Proiectil->getY() - m_Proiectil->getStep())->getInterEntity();
	if (dynamic_cast<iZombie*>(current) != nullptr)
	{
		conOut(m_Proiectil->getX(), m_Proiectil->getY() - m_Proiectil->getStep()) << " ";
		m_Proiectil->setY(coordY + 2);
		current->setHealth(current->getHealth() - this->m_Proiectil->getDamage());
		if (current->getHealth() <= 0)
		{
			Game::addToScore(100);
		}
		Game::setIteration(70);
	}
	else
	{
		conOut(m_Proiectil->getX(), m_Proiectil->getY() - m_Proiectil->getStep()) << " ";
		std::cout << *this->m_Proiectil;
		if (m_Proiectil->getY() >= 105)
		{
			conOut(m_Proiectil->getX(), m_Proiectil->getY()) << " ";
			m_Proiectil->setY(coordY + 2);
		}
		else
		{
			m_Proiectil->move();
		}
	}
}
