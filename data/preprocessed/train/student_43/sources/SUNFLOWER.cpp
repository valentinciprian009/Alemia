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
#include "SUNFLOWER.h"
#include "Sun.h"

using namespace std;

SUNFLOWER::SUNFLOWER() : Plants("PF", 30, 1, 3)
{

}

SUNFLOWER::SUNFLOWER(int cost, int delay, string planta, int resistance) : Plants(planta, resistance, cost, delay)
{

}

void SUNFLOWER::set_obiect(Sun &obiect)
{

	this->ob.set_string(obiect.get_string());
	this->ob.set_aparitie(obiect.get_aparitie());
	this->ob.set_timp(obiect.get_timp());
	this->ob.set_valoare(obiect.get_valoare());
	this->ob.set_x(obiect.get_x());
	this->ob.set_y(obiect.get_y());

}

Sun SUNFLOWER::get_obiect()
{

	return this->ob;

}

SUNFLOWER::~SUNFLOWER()
{

}
