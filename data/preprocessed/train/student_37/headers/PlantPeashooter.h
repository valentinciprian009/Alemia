#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"
#include "SurfaceContainer.h"
#include "Surface.h"
#include "Zombie.h"

using namespace std;

class Plant;
class PlantPeashooter : public Plant
{
public:
	PlantPeashooter(int health);
	~PlantPeashooter();

	int fire(int surface_number);
};

