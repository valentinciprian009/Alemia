#include "PlantShooter.h"
#include "Game.h"
#include "iZombie.h"

int PlantShooter::getPrice() const
{
	return m_Price;
}

int PlantShooter::getAttackFrequency() const { return this->m_attackFrequency;}

PlantShooter::PlantShooter(int x, int y, int health, int freq, Projectile* proiectil, int pret) : Plant(x, y, health, pret), m_attackFrequency(freq), m_Proiectil(proiectil) {}

PlantShooter::~PlantShooter()
{
	this->colors.clear();
	delete m_Proiectil;
}

void PlantShooter::action() 
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

void PlantShooter::setX(int x)
{
	Entity::setX(x);
	m_Proiectil->setX(x);
}

void PlantShooter::setY(int y)
{
	Entity::setY(y);
	m_Proiectil->setY(y + 2);
}


