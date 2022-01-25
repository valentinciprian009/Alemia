#pragma once
#include "ContainerRectangle.h"
#include "Wallnut.h"
#include "Sunflower.h"
#include "Peashooter.h"
#include "SnowPea.h"
#include "FrozenPea.h"
#include "CherryBomb.h"
#include <map>

class PlantChooser
	: public iDrawable
{
protected:
	std::map<ContainerRectangle<iPlant*>*, bool> availablePlants;

	void printPrices() const;

public:
	PlantChooser();
	~PlantChooser();

	bool isInside(int x, int y) const;

	void print() const override;

	iPlant* getClickedPlant(int x, int y); //makes the plant unavailable for 3 turns

};

