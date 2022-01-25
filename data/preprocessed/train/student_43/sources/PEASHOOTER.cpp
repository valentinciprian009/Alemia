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
#include "PEASHOOTER.h"
#include "Pea.h"

using namespace std;

void PEASHOOTER::set_obiect(Pea &obiect)
{
	
	this->ob.set_proiectil(obiect.get_proiectil());
	this->ob.set_damage(obiect.get_damage());
	this->ob.set_speed(obiect.get_speed());

}

Pea PEASHOOTER::get_obiect()
{

	return this->ob;

}

void PEASHOOTER::set_cadenta_tragere(int cadenta_tragere)
{

	this->cadenta_tragere = cadenta_tragere;

}

int PEASHOOTER::get_cadenta_tragere()
{
	return this->cadenta_tragere;
}

PEASHOOTER::PEASHOOTER(string planta, int cadenta_tragere, int cost, int delay, int resistance) : Plants(planta, resistance, cost, delay)
{

	this->cadenta_tragere = cadenta_tragere;

}

PEASHOOTER::PEASHOOTER() : Plants("PS", 500, 2, 5)
{

	this->cadenta_tragere = cadenta_tragere;

}

PEASHOOTER::~PEASHOOTER()
{

}