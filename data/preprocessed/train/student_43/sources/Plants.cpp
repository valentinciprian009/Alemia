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
#include "Plants.h"

using namespace std;

Plants::Plants()
{

	this->plant = "P";
	this->cost = 0;
	this->resistance = 0;
	this->delay = 0;
	this->x = -1;
	this->y = -1;

}

Plants::Plants(string plant, int resistance, int cost, int delay)
{

	this->plant = plant;
	this->cost = cost;
	this->delay = delay;
	this->resistance = resistance;
	this->x = -1;
	this->y = -1;

}

Plants::~Plants()
{

}

void Plants::set_resistance(int resistance)
{
	
	this->resistance = resistance;

}

void Plants::set_cost(int cost)
{

	this->cost = cost;

}

void Plants::set_delay(int delay)
{

	this->delay = delay;

}

void Plants::set_plant(string name_flower)
{
	
	this->plant = name_flower;

}

void Plants::set_x(int x)
{

	this->x = x;

}

int Plants::get_x()
{
	return this->x;
}

void Plants::set_y(int y)
{

	this->y = y;

}

int Plants::get_y()
{
	return this->y;
}

int Plants::get_resistance()
{

	return this->resistance;

}

int Plants::get_cost()
{

	return this->cost;

}

int Plants::get_delay()
{
	
	return this->delay;

}

string Plants::get_plant()
{

	return this->plant;

}