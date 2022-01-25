#include "CPlants.h"

#include <iostream>

#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <time.h>
#include <chrono>

using namespace std::chrono;


void CPlants::delete_planta(int x, int y)
{

}

int CPlants::get_x_plant()
{
	return this->x_coord;
}

int CPlants::get_y_plant()
{
	return this->y_coord;
}

int CPlants::hurt()
{
	static auto begin = steady_clock::now();

	auto end = steady_clock::now();


	if (duration_cast<seconds>(end - begin).count() > 3)
	{
		begin = end;
		this->n_muscaturi--;
	}

	if (this->n_muscaturi == 0)
		return 0;
	
	return 1;

}

void CPlants::get_coord()
{

	std::cout << this->x_coord << "mama " << this->y_coord <<this->cost<< std::endl;

}

void CPlants::afiseaza_planta(int x, int y)
{
	std::cout << "Planta";
}

int CPlants::get_cost()
{
	return this->cost;
}

CPlants::CPlants()
{
}

CPlants::~CPlants()
{
}
