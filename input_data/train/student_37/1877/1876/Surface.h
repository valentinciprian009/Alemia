#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Zombie.h"
#include <map>
#include "Plant.h"
using namespace std;
class Plant;
class Zombie;

class Surface
{
private:
	map<Zombie*, int> positions;
	vector<Plant*> plants_positions;

public:
	Surface();
	~Surface();

	void place_plant(Plant* plant, int position) {
		this->plants_positions[position] = plant;
	}

	void place_zombie(Zombie* zombie);
	map<Zombie*, int>& get_positions() {
		return this->positions;
	}


	void move_zombie(Zombie* zombie, int position) {
		positions[zombie] = position;
	}
	vector<Plant*>& get_plants_positions() {
		return this->plants_positions;
	}

	vector<Zombie*> get_zombies_at_position(int position) {
		map<Zombie*, int>::iterator it;
		vector<Zombie*> living_zombies;

		for (it = positions.begin(); it != positions.end(); it++)
		{
			Zombie* zombie = it->first;
			int zposition = it->second;
			if (zposition == position ) {
				living_zombies.push_back(zombie);
			}
		}
		return living_zombies;
	}
};

