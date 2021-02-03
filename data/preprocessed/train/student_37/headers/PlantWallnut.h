#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"

using namespace std;

class Plant;
class PlantWallnut : public Plant
{
public:
	PlantWallnut(int health);
	~PlantWallnut();

	int fire(int surface_number) {
		// does nothing, wallnut is just a wall
		return 9999;
	}
};

