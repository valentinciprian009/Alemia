#include "PlantChooser.h"

PlantChooser::PlantChooser()
{
	Sunflower* sun = new Sunflower(6, 14);
	auto rectangSun = new ContainerRectangle<iPlant*>(5, 10, sun);
	availablePlants.insert(std::pair<ContainerRectangle<iPlant*>*, bool>(rectangSun, true));

	Wallnut* wall = new Wallnut(13, 15);
	auto rectangWall = new ContainerRectangle<iPlant*>(11, 10, wall);
	availablePlants.insert(std::pair<ContainerRectangle<iPlant*>*, bool>(rectangWall, true));

	Pea* pea = new Pea(19, 15);
	Peashooter* peashoot = new Peashooter(19, 15, pea);
	auto rectangPea = new ContainerRectangle<iPlant*>(17, 10);
	rectangPea->addEntity(peashoot);
	availablePlants.insert(std::pair<ContainerRectangle<iPlant*>*, bool>(rectangPea, true));

	FrozenPea* fpea = new FrozenPea(25, 15);
	SnowPea* fpeashoot = new SnowPea(25, 15, fpea);
	auto rectangFPea = new ContainerRectangle<iPlant*>(23, 10);
	rectangFPea->addEntity(fpeashoot);
	availablePlants.insert(std::pair<ContainerRectangle<iPlant*>*, bool>(rectangFPea, true));

	CherryBomb* cherry = new CherryBomb(31, 14);
	auto rectangCherry = new ContainerRectangle<iPlant*>(29, 10, cherry);
	availablePlants.insert(std::pair<ContainerRectangle<iPlant*>*, bool>(rectangCherry, cherry));
}

void PlantChooser::print() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(15);

	for (auto rectang : availablePlants)
	{
		rectang.first->print();
	}

	printPrices();
}

PlantChooser::~PlantChooser()
{
	availablePlants.clear();
}

bool PlantChooser::isInside(int x, int y) const
{
	for (auto rectang : availablePlants)
	{
		if ((rectang.first->isInside(x, y) == true))
		{
			return true;
		}
	}
	return false;
}

iPlant* PlantChooser::getClickedPlant(int x, int y)
{
	for (auto rectang : availablePlants)
	{
		if ((rectang.first->isInside(x, y) == true) && (rectang.second == true))
		{
			rectang.second = false;
			return rectang.first->getInterEntity();
		}
	}
	return nullptr;
}

void PlantChooser::printPrices() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	for (auto rectang : availablePlants)
	{
		conOut(rectang.first->getX() + 2, rectang.first->getY() - 10) << "Pret: " << rectang.first->getInterEntity()->getPrice();
	}
}
