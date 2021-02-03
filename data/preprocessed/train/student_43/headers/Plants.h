#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <Windows.h>
#include <chrono>
#include "Proiectil.h"
#include "Pea.h"
#include "Frozen_Pea.h"

using namespace std;

class Plants
{

protected:

	string plant;
	int resistance;
	int cost;
	int delay;
	int x;
	int y;


public:

	Plants();

	Plants(string plant, int resistance, int cost, int delay);

	~Plants();

	void set_resistance(int resistance);

	void set_cost(int cost);

	void set_delay(int delay);

	void set_plant(string name_flower);

	void set_x(int x);

	int get_x();

	void set_y(int y);

	int get_y();

	int get_resistance();

	int get_cost();

	int get_delay();

	string get_plant();

	int get_resistance() const { return this->resistance; };

	int get_cost() const { return this->cost; };

	int get_delay() const { return this->delay; };

	string get_plant() const { return this->plant; };

	int get_x() const { return this->x; };

	int get_y() const { return this->y; };

};