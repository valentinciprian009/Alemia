#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"
#include "SurfaceContainer.h"
#include "Surface.h"
#include "Zombie.h"


using namespace std;

class PlantCherryBomb : public Plant
{
private:
	void deal_damage_to_lane(Surface* surface, int cb_position);
public:
	PlantCherryBomb(int health) ;
	~PlantCherryBomb();

	int fire(int surface_number);
};

