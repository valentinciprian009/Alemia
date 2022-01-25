#include "iPlants.h"
class GardenPlants : public iPlants
{
	int time_selected;
	int time_rest;
	int resources;
	bool selected;
public:

	GardenPlants(string t, int h, int ts, int tr, int r) : iPlants(t, h), time_selected(ts), time_rest(tr), resources(r) 
	{
		selected = false;
	}

	void set_time_selected(int ts);
	void set_selected(bool s);

	int get_time_selected();
	int get_time_rest();
	int get_resources();
};

