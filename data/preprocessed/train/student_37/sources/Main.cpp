#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <thread>
#include "Strategy.h"
#include "StrategyBucketHead.h"
#include "StrategyRegular.h"
#include "Zombie.h"
#include "SurfaceContainer.h"
#include "Surface.h"
#include "Logger.h"
#include <map>
#include "Plant.h"
#include "PlantPeashooter.h"
#include "PlantSunflower.h"
#include "PlantWallnut.h"
#include <omp.h>
#include <sstream>
#include <iterator>
#include <exception>
#include "PlantCherryBomb.h"
#include <random>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#define MAX_ZOMBIES 4

class Strategy;
class StrategyBucketHead;
class StrategyRegular;
class Zombie;
class Surface;
class SurfaceContainer;
class PlantCherryBomb;

using namespace std::chrono;

//void doLoadingBar()
//{
//	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
//	static auto begin = steady_clock::now();
//	static int col = COL_FIRST_STAR_POSITION;
//	static std::string printedChar = "*";
//
//	auto end = steady_clock::now();
//	if (duration_cast<milliseconds>(end - begin).count() > 150)
//	{
//		begin = end;
//		conOut(ROW_TITLE + 1, col) << printedChar;
//		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
//			if (printedChar == "*")
//			{
//				printedChar = " ";
//			}
//			else
//			{
//				printedChar = "*";
//			}
//			col = COL_FIRST_STAR_POSITION;
//		}
//		else
//		{
//			col += COL_DISTANCE_BETWEEN_STARS;
//		}		
//	}
//}

struct Coordinates {
	int x;
	int y;
};

struct LaneCoordinates {
	int lane_number;
	int lane_position; // (column)
};


void clear_view(int start_row, int start_col) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < MAX_ZOMBIES; j++) {
			conOut(start_row + j, start_col + i) << " ";
		}
	}
}




void view(Surface* surface, int start_row, int start_col) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	map<Zombie*, int> positions = surface->get_positions();
	int positions_taken[9];
	for (int i = 0; i < 9; i++) {
		positions_taken[i] = 0;
	}
	map<Zombie*, int>::iterator it;

	


	conOut(start_row , start_col-1 ) << "|";

	for (int i = 0; i < 40; i++) {
		conOut(start_row + 9, start_col + i) << "_";
	}

	for (it = positions.begin(); it != positions.end(); it++)
	{
		Zombie* zombie = it->first;
		int pos = it->second;
		if(!zombie->is_dead()){
			positions_taken[pos]++;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < positions_taken[i]; j++) {
			conOut(start_row + j, start_col + i) << "Z";
		}
	}
	for (int i = 0; i < surface->get_plants_positions().size(); i++) {
		if (surface->get_plants_positions()[i] != NULL) {
			Plant* plant = surface->get_plants_positions()[i];
			if (!plant->is_dead()) {

				conOut(start_row, start_col + i) << plant->get_type();
			}
		}
	}


}	



Plant* pick_plant(Coordinates* clicked_coordinates) {
	if ((clicked_coordinates->x == 10 || clicked_coordinates->x == 11) && (clicked_coordinates->y >= 0 && clicked_coordinates->y <= 9)) {
		return new PlantPeashooter(200);
	}

	if ((clicked_coordinates->x == 10 || clicked_coordinates->x == 11) && (clicked_coordinates->y >= 10 && clicked_coordinates->y <= 19)) {
		return new PlantWallnut(400);
	
	}
	if ((clicked_coordinates->x == 10 || clicked_coordinates->x == 11) && (clicked_coordinates->y >= 20 && clicked_coordinates->y <= 29)) {
		return new PlantSunflower(100);
	}
	if ((clicked_coordinates->x == 10 || clicked_coordinates->x == 11) && (clicked_coordinates->y >= 30 && clicked_coordinates->y <= 39)) {
		return new PlantCherryBomb(200);
	}
	if ((clicked_coordinates->x == 10 || clicked_coordinates->x == 11) && (clicked_coordinates->y >= 40 && clicked_coordinates->y <= 49)) {
		return NULL;
	}
	return NULL;
}

void place_plant(Plant* selected_plant, Coordinates destination) {
	if (selected_plant == NULL) {
		return;
	}

}

class CannotPlaceException : public exception {

};

class InsufficientLanesException : public exception {

};

LaneCoordinates* getLaneCoordinates(Coordinates* mouse_coordinates) {
	int rand = mouse_coordinates->y;
	int coloana = mouse_coordinates->x;

	if (coloana < 20 || coloana > (20 + 9 * 2)) {
		CannotPlaceException ex;
		throw ex;
	}



	

	int lane_coords = -1;
	int lane_column = -1;

	lane_coords = rand / 10;

	// lane_coords = al catelea lane

	int nr_surfaces = SurfaceContainer::get_instanta()->get_surfaces().size();
	if (nr_surfaces < lane_coords + 1) {
		InsufficientLanesException ex;
		throw ex;
	}
	lane_column = (coloana - 20);
	LaneCoordinates* result = new LaneCoordinates;
	result->lane_number = lane_coords;
	if(lane_column == 9){
		result->lane_position = lane_column -1;
	}
	else {
		result->lane_position = lane_column;
	}
	

	return result;
	
}

Coordinates* getCoordinates(string action) {
	int length = action.length();
	action = action.substr(3);
	string str = action;
	if (str.size() > 0)  str.resize(str.size() - 1);
	// action[action.length()-2] = '\0';

		

	std::istringstream iss(str);
	
	int x;
	iss >> x;
	int y;
	iss >> y;

	Coordinates* coords = new Coordinates;
	coords->x = x;
	coords->y = y;
	return coords;
}

void erase_row(int row_no) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 100; i++) {
		conOut(row_no, i) << " ";
	}
}


//int get_lane_number(Coordinates* coords) {
//	if
//}


// Enunt tema: https://213.177.4.166/dokuwiki/poo/lab/tema2

int main(void)
{
	SurfaceContainer* sc = SurfaceContainer::get_instanta();

	

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	bool has_selected_level = false;
	while(!has_selected_level){
		conOut(0, 40) << "SELECT LEVEL";
		conOut(1, 40) << "Level 1";
		conOut(2, 40) << "Level 2";
		conOut(3, 40) << "Level 3";
		// user clicked 1 40   1 50   level 1
		// user clicked 2 40   2 50   level 2
		// user clicked 3 40   3 50   level 3
		std::string action = conIn.getUserActions();
		conOut(10, 40) << action;
		if (action.find("dc") != string::npos)
		{
			Coordinates* coords = getCoordinates(action);
			int y = coords->x;
			int x = coords->y;
			if (x == 1 && (y >= 40 && y <= 50)) {
				conOut(20, 40) << "Selected Level 1";
				Surface* surf = new Surface();
				sc->add_surface(surf);
				has_selected_level = true;
			}else if (x == 2 && (y >= 40 && y <= 50)) {
				conOut(20, 40) << "Selected Level 2";
				Surface* surf = new Surface();
				Surface* surf2 = new Surface();
				sc->add_surface(surf);
				sc->add_surface(surf2);
				has_selected_level = true;
			}else if (x == 3 && (y >= 40 && y <= 50)) {
				conOut(20, 40) << "Selected Level 3";
				Surface* surf = new Surface();
				Surface* surf2 = new Surface();
				Surface* surf3 = new Surface();
				sc->add_surface(surf);
				sc->add_surface(surf2);
				sc->add_surface(surf3);
				has_selected_level = true;
			}
		}
		if (has_selected_level) {
			for (int i = 0; i < 154; i++) {
				for (int j = 0; j < 41; j++) {
					conOut(i, j) << " ";
				}
			}
		}
	}

	
	

	Logger log("C:/temp/log.txt");

	conOut(0, 10) << "PS";
	conOut(10, 10) << "WN";
	conOut(20, 10) << "SF";
	conOut(30, 10) << "CB";
	conOut(40, 10) << "SP";

	
	Plant* selected_plant = NULL;

	bool game_not_over = true;
#pragma omp parallel num_threads(2), shared(game_not_over)
	{

#pragma omp sections 
		{
#pragma omp section
			{

				while (game_not_over) {
#pragma omp critical
					{



					std::string action = conIn.getUserActions();
					if (action != "")

					{
							// str.find(str2) != string::npos
							if(action.find("dc") != string::npos)
							{
								Coordinates* coords = getCoordinates(action);
								if(selected_plant != NULL && coords != NULL){
									log.log("trying to place plant at coordinates: " + to_string(coords->x) + " and " + to_string(coords->y));
								}
								erase_row(41);

								if(selected_plant == NULL){
									selected_plant = pick_plant(coords);
									if (selected_plant != NULL) {
										conOut(40, 2) << "PS";
									}
								}
								else {
									// plant is already picked
									// check if we can set the plant on a specific lane
									

									LaneCoordinates* lane_coords = NULL; 
									try{
										lane_coords = getLaneCoordinates(coords);
									}
									catch (CannotPlaceException ex) {
										log.log("CANNOT PLACE PLANT AT COORDINATES: " + to_string(coords->x) + " x " + to_string(coords->y));
										conOut(37, 2) << "CANNOT PLACE PLANT AT COORDINATES: " + to_string(coords->x) + " x " + to_string(coords->y);
									}
									catch (InsufficientLanesException ex) {
										log.log("INSUFFICIENT LANES: " + to_string(coords->x) + " x " + to_string(coords->y));
										conOut(37, 2) << "Cannot place on inexistent lane";
									}
									if(lane_coords != NULL){
										erase_row(39);
										conOut(39, 2) << lane_coords->lane_number << " " << lane_coords->lane_position;
										log.log("trying to place plant at lane coords: " + to_string(lane_coords->lane_number) + " " + to_string(lane_coords->lane_position));
										Surface* surface_to_place_plant_on = sc->get_instanta()->get_surfaces()[lane_coords->lane_number];
										bool can_place = true;
										map<Zombie*, int> positions_take_by_zombies = surface_to_place_plant_on->get_positions();

										map<Zombie*, int>::iterator it;
										for (it = positions_take_by_zombies.begin(); it != positions_take_by_zombies.end(); it++) {
											Zombie* zombie = it->first;
											
											if (it->second == lane_coords->lane_position && !zombie->is_dead()) {
												can_place = false;
												break;
											}
										}
										
										if (surface_to_place_plant_on->get_plants_positions()[lane_coords->lane_position] != NULL) {
											can_place = false;
										}
										
										if (can_place) {
											log.log("CAN PLACE PLANT at coordintates: " + to_string(lane_coords->lane_number) + " " + to_string(lane_coords->lane_position));
										}
										else {
											log.log("CANNOT PLACE PLANT at coordintates: " + to_string(lane_coords->lane_number) + " " + to_string(lane_coords->lane_position));
										}
										

										if (can_place) {
											surface_to_place_plant_on->get_plants_positions()[lane_coords->lane_position] = selected_plant;
											selected_plant = NULL;
										}
										
										
									}
								}
								conOut(41, 2) << coords->x << " " <<  coords->y;
							}
						}
					}
				}
			}
#pragma omp section
			{
				int index = 0;
				int suns[9] = { 0 };
				while (game_not_over) {
					index++;

					vector<Surface*>& surfaces = sc->get_surfaces();
					for (int i = 0; i < surfaces.size(); i++) {
						Surface* sf = surfaces[i];
						

						vector<Zombie*> zbs = sf->get_zombies_at_position(0);
						for (int k = 0; k < zbs.size(); k++) {
							if (zbs[k] != NULL && !zbs[k]->is_dead()) {
								game_not_over = false;
								conOut(40, 30) << "GAAAAAAAAAAAAAAAAAAAAAME OOOOOOVVEEEEEEEER!!!!!!!! Sorry Bro! :'(";
								break;
							}
						}
								
						
						
					}
				

					std::random_device dev;
					std::mt19937 rng(dev());
					std::uniform_int_distribution<std::mt19937::result_type> dist_sun(0, 8); // distribution in range [1, 6]
					int sunNr = dist_sun(rng);
					suns[sunNr] = 1;

					for (int i = 0; i < 9; i++) {
						if (suns[i]) {
							conOut(30, 70 + 4 * i) << "SUN";
						}
					}
					
					

					for (int i = 0; i < sc->get_surfaces().size(); i++) {
						clear_view((i) * 10, 20);
						view(sc->get_surfaces()[i], (i) * 10, 20);
					}

					Surface* surface = sc->get_surfaces()[0];
					// log.log("BEFORE");
					sc->move();
					// std::this_thread::sleep_for(std::chrono::milliseconds(1000));

					if (index % 3 == 0) {
						int nr_lanes = sc->get_surfaces().size();
						std::random_device dev;
						std::mt19937 rng(dev());
						std::uniform_int_distribution<std::mt19937::result_type> dist_zombie(1, 2); // distribution in range [1, 6]
						std::uniform_int_distribution<std::mt19937::result_type> dist_surface(0, nr_lanes-1);
						

						int random_surface = dist_surface(rng);
						int random_zombie = dist_zombie(rng);
						Zombie* rzombie = NULL;
						if (random_zombie == 0) {
							rzombie = new Zombie(new StrategyRegular(), 300, 50);
						}else 
						if (random_zombie == 1) {
							rzombie = new Zombie(new StrategyBucketHead(), 500, 100);
							
							
						}
						if (rzombie != NULL) {
							Surface* surf = sc->get_surfaces()[random_surface];
							surf->place_zombie(rzombie);
							surf->move_zombie(rzombie, 7);
						}

					}
					Sleep(1000);
				}
			}
		}

		
	}

	system("pause");
	return 0;
}

