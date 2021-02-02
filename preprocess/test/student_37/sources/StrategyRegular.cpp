#include "StrategyRegular.h"



StrategyRegular::StrategyRegular()
{
}


StrategyRegular::~StrategyRegular()
{
}


bool StrategyRegular::execute_move(Zombie* zombie, int surface_number) {
	SurfaceContainer* sc = SurfaceContainer::get_instanta();
	Surface* surface = sc->get_surfaces()[surface_number];
	map<Zombie*, int> positions = surface->get_positions();
	int pozitie_zombie_curent = positions[zombie];
	bool exista_planta_inainte = false;
	
	if (pozitie_zombie_curent == 0) {
		// TODO: end game
		return true;
	}
	Plant* plant_inainte = surface->get_plants_positions()[pozitie_zombie_curent - 1];
	if (pozitie_zombie_curent > 0 && plant_inainte != NULL && !plant_inainte->is_dead()) {
		exista_planta_inainte = true;
		return false;
	}
	

	return true;
}