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

using namespace std;

class BucketHead_Zombie : virtual public Zombie
{

public:

	BucketHead_Zombie();

	BucketHead_Zombie(string zombie, int zspeed, int zlife, int zdamage);

	~BucketHead_Zombie();

	void print();

	// friend ostream& operator<< (ostream &out, const BucketHead_Zombie &ob);

};