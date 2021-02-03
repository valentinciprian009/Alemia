#include "GardenPlants.h"

void GardenPlants::set_time_selected(int ts)
{
	time_selected = ts;
}

void GardenPlants::set_selected(bool s)
{
	selected = s;
}

int GardenPlants::get_time_selected()
{
	return time_selected;
}

int GardenPlants::get_time_rest()
{
	return time_rest;
}

int GardenPlants::get_resources()
{
	return resources;
}
