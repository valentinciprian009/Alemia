#include "PlantPeashooter.h"



PlantPeashooter::PlantPeashooter(int health) : Plant(health, "P")
{
}


PlantPeashooter::~PlantPeashooter()
{
}

int PlantPeashooter::fire(int surface_no) {
	SurfaceContainer* sc = SurfaceContainer::get_instanta();
	Surface* surface = sc->get_surfaces()[surface_no];
	map<Zombie*, int>& positions = surface->get_positions();

	int pozitie_planta_curenta = -1;
	int pozitie_primul_zombie_viu = 9999;

	vector<Plant*>& plants = surface->get_plants_positions();
	for (int i = 0; i < plants.size(); i++) {
		if (plants[i] == this) {
			pozitie_planta_curenta = i;
		}
	}

	// TODO: if pozitie_planta_curenta == -1   throw exception

	map<Zombie*, int>& zombies_pos = surface->get_positions();
	map<Zombie*, int>::iterator it;


	for (it = zombies_pos.begin(); it != zombies_pos.end(); it++) {
		int pozitie_zombie = it->second;
		Zombie* zombie = it->first;
		if (zombie->is_dead()) {
			continue;
		}
		if (pozitie_primul_zombie_viu > pozitie_zombie && pozitie_zombie >= pozitie_planta_curenta) {
			pozitie_primul_zombie_viu = pozitie_zombie;
		}
	}
	for (it = zombies_pos.begin(); it != zombies_pos.end(); it++){
		int pozitie_zombie = it->second;
		Zombie* zombie = it->first;
		if (pozitie_zombie == pozitie_primul_zombie_viu && !zombie->is_dead()) {
			
			
			zombie->take_damage(200); // TODO: remove HARDCODING
			break;
		}
	}

	return pozitie_primul_zombie_viu;

}
