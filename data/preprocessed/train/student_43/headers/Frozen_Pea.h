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
#include "Proiectil.h"
#include "Pea.h"

using namespace std;

class Frozen_Pea :	public Pea
{

	int scade_speed;

public:
	
	Frozen_Pea();

	Frozen_Pea(string proiectil, int speed, int damage, int scade_speed);

	~Frozen_Pea();

	void set_scade_speed(int scade_speed);

	int get_scade_speed();

	int get_scade_speed() const { return this->scade_speed; };


};