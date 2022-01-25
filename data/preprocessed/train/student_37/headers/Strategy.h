#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Zombie.h"
#include "SurfaceContainer.h"
#include "Surface.h"


using namespace std;

class Zombie;

class Strategy
{
public:
	Strategy();
	~Strategy();

	virtual bool execute_move(Zombie* zombie, int surface_number) = 0;
};

