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

class PoleVaulting_Zombie : virtual public Zombie
{

protected:

	int jump;

public:

	PoleVaulting_Zombie(string zombie, int zspeed, int zlife, int zdamage, int jump);

	PoleVaulting_Zombie();

	~PoleVaulting_Zombie();

	void set_jump(int jump);

	int get_jump();

	int get_jump() const { return this->jump; };

	void print();

	//friend ostream& operator<< (ostream& out, const PoleVaulting_Zombie &ob);

};