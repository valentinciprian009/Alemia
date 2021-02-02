#include "Surface.h"



Surface::Surface()
{
	for (int i = 0; i < 9; i++) {
		this->plants_positions.push_back(NULL);
	}
}


Surface::~Surface()
{
}

void Surface::place_zombie(Zombie * zombie)
{
	positions.insert(pair<Zombie*, int>(zombie, 12));
}
