#include "SunZone.h"

void SunZone::printInteriors() const
{
	for (auto iter : sunRectangles)
	{
		if(iter->getInterEntity() != nullptr)
			std::cout << *iter->getInterEntity();
	}
}

SunZone::SunZone()
{
	int pozY = 25;
	const int offsetY = 9;
	for (int i = 0; i < this->count; i++, pozY += offsetY)
	{
		sunRectangles.push_back(new ContainerRectangle<iResource*>(0, pozY));
	}
}

void SunZone::generateSun(const int& val)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	srand(time(NULL));
	int poz = rand() % 9;
	auto current = sunRectangles.begin() + poz;

	(*current)->addEntity(new Sun((*current)->getX() + 2, (*current)->getY() + 3, val));
	
}

void SunZone::print() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(15);
	auto i = sunRectangles.begin();
	(*i)->print();

	for (i = sunRectangles.begin() + 1; i != sunRectangles.end() - 2; i++)
	{
		(*i)->printSusInterior(15);
	}

	(*(i + 1))->print();
	(*i)->printSusInterior(15);
	printInteriors();
}


bool SunZone::isInside(int x, int y)
{
	for (auto iter : sunRectangles)
	{
		if ((iter->isInside(x, y)) && (iter->getInterEntity() != nullptr))
		{
			delete iter->getInterEntity();
			iter->addEntity(nullptr);
			iter->erase();
			return true;
		}
	}
	return false;
}