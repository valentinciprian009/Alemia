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

class Zombie
{

protected:

	string zombie;
	int zspeed;
	int zdamage;
	int zlife;
	int x;
	int y;

public:

	Zombie(string zombie, int zspeed, int zdamage, int zlife);

	Zombie();

	~Zombie();

	void set_zspeed(int zpeed);

	void set_zombie(string zombie);

	void set_zlife(int zlife);

	void set_zdamage(int zdamage);

	void set_x(int x);

	void set_y(int y);

	string get_zombie() const { return this->zombie; };

	int get_zdamage() const { return this->zdamage; };

	int get_zlife() const { return this->zlife; };

	int get_zspeed() const { return this->zspeed; };

	int get_x() const { return this->x; };

	int get_y() const { return this->y; };

	string get_zombie();

	int get_zdamage();

	int get_zlife();

	int get_zspeed();

	int get_x();

	int get_y();

	virtual void print();

	//friend ostream& operator<< (ostream &out, const Zombie &ob);

};