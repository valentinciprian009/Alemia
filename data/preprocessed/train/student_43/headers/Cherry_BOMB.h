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
#include <conio.h>
#include "Plants.h"

using namespace std;

class Cherry_BOMB :	public Plants
{

	int time_bomb;
	int power;
	int valability;

public:

	Cherry_BOMB(string planta, int cost, int delay, int resistance, int power, int time_bomb, int valability);

	Cherry_BOMB();

	void set_time_bomb(int time_bomb);

	void set_power(int power);

	void set_valability(int valability);

	int get_time_bomb();

	int get_valability();

	int get_power();

	int get_time_bomb() const { return this->time_bomb; };

	int get_valability() const { return this->valability; };

	int get_pwer() const { return this->power; };

	~Cherry_BOMB();

};