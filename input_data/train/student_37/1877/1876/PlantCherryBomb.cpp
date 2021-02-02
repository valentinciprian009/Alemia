#include "PlantCherryBomb.h"




PlantCherryBomb::PlantCherryBomb(int health) : Plant(health, "C")
{
}


PlantCherryBomb::~PlantCherryBomb()
{
}


void PlantCherryBomb::deal_damage_to_lane(Surface * surface, int cb_position)
{
	map<Zombie*, int>& zombies_pos = surface->get_positions();

	vector<Zombie*> zombies_to_receive_damage;
	if (cb_position == 0) {
		vector<Zombie*> living_zombies = surface->get_zombies_at_position(0);
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies.begin(), living_zombies.end());
		vector<Zombie*> living_zombies1 = surface->get_zombies_at_position(1);
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies1.begin(), living_zombies1.end());
	}
	else if (cb_position == 8) {
		vector<Zombie*> living_zombies8 = surface->get_zombies_at_position(8);
		vector<Zombie*> living_zombies7 = surface->get_zombies_at_position(7);
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies8.begin(), living_zombies8.end());
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies7.begin(), living_zombies7.end());

	}
	else {
		vector<Zombie*> living_zombies_before = surface->get_zombies_at_position(cb_position-1);
		vector<Zombie*> living_zombies_this = surface->get_zombies_at_position(cb_position);
		vector<Zombie*> living_zombies_after = surface->get_zombies_at_position(cb_position+1);
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies_before.begin(), living_zombies_before.end());

		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies_this.begin(), living_zombies_this.end());
		zombies_to_receive_damage.insert(zombies_to_receive_damage.end(), living_zombies_after.begin(), living_zombies_after.end());

	}

	// deal damage to zombies
	for (int i = 0; i < zombies_to_receive_damage.size(); i++) {
		Zombie* zombie = zombies_to_receive_damage[i];
		zombie->take_damage(1000); // TODO: adjust cherry-bomb damage rate
	}
}


int PlantCherryBomb::fire(int surface_no) {

	// surface_no = suprafata pe care e cherry bomb-ul


	SurfaceContainer* sc = SurfaceContainer::get_instanta();

	int numar_suprafete = sc->get_nr_surfaces();
	// 1, 3, 5
	Surface* surface_above = NULL;
	Surface* surface_in_front = NULL;
	Surface* surface_below = NULL;

	


	if (numar_suprafete == 1) {
		surface_in_front = sc->get_surfaces()[0];
	}
	else if (numar_suprafete == 3 || numar_suprafete == 5) {
		surface_in_front = sc->get_surfaces()[surface_no];
		if (surface_no > 0) {
			surface_above = sc->get_surfaces()[surface_no-1];
		}
		if (surface_no < sc->get_nr_surfaces() - 1) {
			surface_below = sc->get_surfaces()[surface_no + 1];
		}
	}

	int pozitie_cb = -1;
	vector<Plant*>& plants = sc->get_surfaces()[surface_no]->get_plants_positions();
	for (int i = 0; i < plants.size(); i++) {
		if (plants[i] == this) {
			pozitie_cb = i;
			break;
		}
	}


	Surface* surfaces[3] = { surface_above, surface_in_front, surface_below };
	for (int i = 0; i < 3; i++) {
		if (surfaces[i] != NULL) {
			deal_damage_to_lane(surfaces[i], pozitie_cb);
		}
	}

	return 9999;



	

}
