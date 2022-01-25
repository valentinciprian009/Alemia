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
#include "Frozen_Pea.h"

using namespace std;

Frozen_Pea::Frozen_Pea(string proiectil, int speed, int damage, int scade_speed) : Pea(proiectil, damage, speed)
{

	this->scade_speed = scade_speed;

}

Frozen_Pea::Frozen_Pea() : Pea("**", 15, 5)
{

	this->scade_speed = -5;

}

void Frozen_Pea::set_scade_speed(int scade_speed)
{

	this->scade_speed = scade_speed;

}

int Frozen_Pea::get_scade_speed()
{

	return this->scade_speed;

}

Frozen_Pea::~Frozen_Pea()
{

}