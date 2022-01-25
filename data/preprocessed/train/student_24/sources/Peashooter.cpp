#include "Peashooter.h"


Peashooter::Peashooter(int x, int y, Projectile* proiectil, int pret) : 
	PlantShooter(x, y, 50, 2, proiectil, pret), 
	Plant(x, y, 50, pret),
	BattleEntity(x, y, 50),
	Entity(x, y) {}

Peashooter::Peashooter(const Peashooter& old) : 
	Entity(old.coordX, old.coordY), 
	BattleEntity(old.coordX, old.coordY, old.m_Health), 
	Plant(old.coordX, old.coordY, old.m_Health, old.m_Price),
	PlantShooter(old.coordX, old.coordY, old.m_Health, 5, nullptr, 100)
{
	this->m_Proiectil = new Pea(old.coordX, old.coordY);
}

iPlant* Peashooter::clone()
{
	return new Peashooter(*this);
}


Peashooter::~Peashooter()
{
}

void Peashooter::print() const
{
	const char head = 153;
	const char mouth = 167;
	const char body = 198;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(10);
	conOut(coordX, coordY) << head;
	conOut(coordX, coordY + 1) << mouth;
	conOut(coordX + 1, coordY) << body;

}

void Peashooter::action()
{
	PlantShooter::action();
}
