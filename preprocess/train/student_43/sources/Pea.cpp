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

Pea::Pea() : Proiectil("--", 5)
{

	this->damage = 15;

}

Pea::Pea(string proiectil, int damage, int speed) : Proiectil(proiectil, speed)
{

	this->damage = damage;

}

void Pea::set_damage(int damage)
{

	this->damage = damage;

}

int Pea::get_damage()
{

	return this->damage;

}

Pea::~Pea()
{

}