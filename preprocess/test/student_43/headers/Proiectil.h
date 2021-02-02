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

using namespace std;

class Proiectil
{

protected:

	string proiectil;
	int speed;
	int x;
	int y;

public:

	Proiectil();

	Proiectil(string proiectil, int speed);
	
	void set_proiectil(string proiectil);

	void set_speed(int speed);

	void set_x(int x);

	void set_y(int y);

	int get_speed() const { return this->speed; };

	string get_proiecil() const { return this->proiectil; };

	int get_speed();

	string get_proiectil();

	int get_x();

	int get_y();

	int get_x() const { return this->x; };

	int get_y() const { return this->y; };

	~Proiectil();

};