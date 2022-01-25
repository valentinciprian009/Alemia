#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Surface.h"
#include "Logger.h"
#include <time.h>
#include <chrono>
#include <thread>
#include "ConsoleOutput.h"


using namespace std;

class Surface;
class Logger;

class SurfaceContainer
{

private:
	int nr_surfaces = 0;
	vector<Surface*> surfaces;
	SurfaceContainer();

	static SurfaceContainer* instanta;
public:
	
	~SurfaceContainer();

	static SurfaceContainer* get_instanta() {
		if (instanta == NULL) {
			instanta = new SurfaceContainer();
		}
		return instanta;
	}

	void set_nr_surfaces(int nr_s) {
		this->nr_surfaces = nr_s;
	}

	int get_nr_surfaces() {
		return this->nr_surfaces;
	}

	void add_surface(Surface* surface) {
		this->nr_surfaces++;
		this->surfaces.push_back(surface);
	}
	vector<Surface*>& get_surfaces() {
		return this->surfaces;
	}


	void move();
	void bullet(int lane_number, int plant_postion, int target_position);
};

