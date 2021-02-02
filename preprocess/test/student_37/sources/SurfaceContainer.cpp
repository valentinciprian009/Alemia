#include "SurfaceContainer.h"
#include <omp.h>


SurfaceContainer::SurfaceContainer()
{
}


SurfaceContainer::~SurfaceContainer()
{
}



void SurfaceContainer::move()
{
	Logger log("C:/temp/log.txt");

	// std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	for (int i = 0; i < surfaces.size(); i++) {
		Surface* surface = surfaces[i];

		// every plant which can fire will fire
		vector<Plant*> plants = surface->get_plants_positions();
		for (int j = 0; j < plants.size(); j++) {
			if(plants[j] != NULL && !plants[j]->is_dead()){
				int target_position = plants[j]->fire(i);
		#pragma omp parallel num_threads(2), shared(target_position)
				{
#pragma omp sections 
					{
#pragma omp section
						{
							if (target_position != 9999) {

								bullet(i, j, target_position);
							}
						}
#pragma omp section
						{

						}
					}
				}


				
				
			}
		}

		// every non-dead zombie which has a plant in front of him should give damage to the plant
		map<Zombie*, int>& zombie_positions = surface->get_positions();
		map<Zombie*, int>::iterator it_zombie_positions;

		for (it_zombie_positions = zombie_positions.begin(); it_zombie_positions != zombie_positions.end(); it_zombie_positions++)
		{
			Zombie* zombie = it_zombie_positions->first;
			vector<Plant*>& plants = surface->get_plants_positions();
			Plant* plant_before_zombie = NULL;
			int zombie_position = it_zombie_positions->second;

			if (zombie->is_dead()) {
				continue;
			}
			
			for (int j = 0; j < plants.size(); j++) {
				if (plants[j] != NULL && !plants[j]->is_dead()) {
					Plant* plant = plants[j];
					if (j == zombie_position - 1) {
						// planta se afla in fata zombie-ului
						plant->take_damage(zombie->get_damage());

					}
					
				}
			}
			
		}


		map<Zombie*, int>& positions = surface->get_positions();
		map<Zombie*, int>::iterator it;
		
		for (it = positions.begin(); it != positions.end(); it++)
		{
			Zombie* zombie = it->first;
			int position = it->second;

			// log.log("move() - before executed to position: " + std::to_string(position));

			Strategy* strategy = zombie->get_strategy();
			if (strategy->execute_move(zombie, i)) {
				if(positions[zombie] > 0){
					it->second--;
				}
				else {
					// TODO: game over
				}
			}
			else {
				// zombie cannot move (plant e in fata)
				Plant* plant = surface->get_plants_positions()[position - 1];
				plant->take_damage(zombie->get_damage());
			}
		}
	}
}

void SurfaceContainer::bullet(int lane_number, int plant_postion, int target_position)
{
	Logger log("C:/temp/log.txt");

	log.log("HIT TARGET AT: " + to_string(target_position) + " ON LANE: " + to_string(lane_number) + " FROM PLANT POSITION: " + to_string(plant_postion	));
	// 
	int position_to_draw_bullet_x = lane_number * 10;
	int position_to_draw_bullet_y = 20 + plant_postion;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	for (int i = 0; i < target_position - plant_postion; i++) {
		conOut(position_to_draw_bullet_x, position_to_draw_bullet_y+i+1) << "~";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

SurfaceContainer* SurfaceContainer::instanta = NULL;