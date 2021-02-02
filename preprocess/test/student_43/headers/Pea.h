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

using namespace std;

class Pea : public Proiectil
{

protected:

	int damage;

public:

	Pea();

	Pea(string proiectil, int damage, int speed);

	~Pea();

	void set_damage(int damage);

	int get_damage();

	int get_damage() const { return this->damage; };

};