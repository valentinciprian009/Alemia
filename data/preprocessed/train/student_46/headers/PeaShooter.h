#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include "Sun.h"
#include "Zombie.h"
#include "PeaShooter.h"
#include "Sun.h"
using namespace std::chrono;
using namespace std;
#define ROW_TITLE					1			
#define COL_FIRST_STAR_POSITION		7
#define COL_DISTANCE_BETWEEN_STARS	10
#define COL_START 1
#define ROW_START 1

class PeaShooter
{
public:
	PeaShooter();
	
	void printThePeaSh();

	void costInSun();

	void lifePlant();

	void attack1();
	void attack2();
	void attack3();

	~PeaShooter();
};

