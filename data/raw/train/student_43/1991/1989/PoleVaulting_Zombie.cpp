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
#include "PoleVaulting_Zombie.h"

using namespace std;

PoleVaulting_Zombie::PoleVaulting_Zombie(string zombie, int zspeed, int zlife, int zdamage, int jump) : Zombie(zombie, zspeed, zdamage, zlife)
{

	this->jump = jump;

}

PoleVaulting_Zombie::PoleVaulting_Zombie() : Zombie("ZP", 2, 25, 300)
{

	this->jump = 1;

}

void PoleVaulting_Zombie::set_jump(int jump)
{

	this->jump = jump;

}

int PoleVaulting_Zombie::get_jump()
{

	return this->jump;

}

void PoleVaulting_Zombie::print()
{

	cout << "Zombie : \t\t\t" << this->zombie << "\nLife : \t\t\t" << this->zlife << "\nSpeed : \t\t\t" << this->zspeed << "\nDamage : \t\t\t" << this->zdamage << "\nJump : \t\t\t" << this->jump << "\n\n\n";

}

//ostream& operator<<(ostream &out, const PoleVaulting_Zombie &ob)
//{
//
//	out << "Zombie : \t\t\t" << ob.get_zombie() << "\nLife : \t\t\t" << ob.get_zlife() << "\nSpeed : \t\t\t" << ob.get_zspeed() << "\nDamage : \t\t\t" << ob.get_zdamage() << "\nJump : \t\t\t" << ob.get_jump() << "\n\n\n";
//
//	return out;
//
//}

PoleVaulting_Zombie::~PoleVaulting_Zombie()
{

}