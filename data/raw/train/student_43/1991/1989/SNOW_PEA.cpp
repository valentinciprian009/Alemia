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
#include "Pea.h"
#include "Frozen_Pea.h"
#include "SNOW_PEA.h"

using namespace std;

SNOW_PEA::SNOW_PEA() : Plants("PN", 100, 4, 2)
{

	this->cadenta_tragere = 1;

}

SNOW_PEA::SNOW_PEA(string planta, int resistance, int cost, int delay, int cadenta_tragere) : Plants(planta, resistance, cost, delay)
{

	this->cadenta_tragere = cadenta_tragere;

}

SNOW_PEA::~SNOW_PEA()
{

}

int SNOW_PEA::get_cadenta_tragere()
{

	return this->cadenta_tragere;

}

void SNOW_PEA::set_cadenta_tragere(int cadenta_tragere)
{

	this->cadenta_tragere = cadenta_tragere;

}

void SNOW_PEA::set_obiect(Frozen_Pea &obiect)
{

	this->obiect.set_damage(obiect.get_damage());
	this->obiect.set_proiectil(obiect.get_proiectil());
	this->obiect.set_speed(obiect.get_speed());
	this->obiect.set_scade_speed(obiect.get_scade_speed());
	this->obiect.set_x(obiect.get_x());
	this->obiect.set_y(obiect.get_y());

}

Frozen_Pea SNOW_PEA::get_obiect()
{

	return this->obiect;

}