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
#include "Zombie.h"
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"

using namespace std;

class Super_Zombie : public BucketHead_Zombie, public PoleVaulting_Zombie
{

	int unic_per_round;
	int random_appearance;

public:

	Super_Zombie(string zombie, int zspeed, int zlife, int zdamage, int jump, int unic, int timp);

	Super_Zombie();

	~Super_Zombie();

	void set_unic_per_round(int unic);

	void set_random_appearance(int timp);

	int get_unic_per_round();

	int get_random_appearance();

	int get_unic_per_round() const { return this->unic_per_round; };

	int get_random_appearance() const { return this->random_appearance; };

	void print();

	//friend ostream& operator<< (ostream &out, const Super_Zombie &ob);

};