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
#include "Super_Zombie.h"
#include "PoleVaulting_Zombie.h"

using namespace std;

Super_Zombie::Super_Zombie(string zombie, int zspeed, int zlife, int zdamage, int jump, int unic, int timp)
{

	BucketHead_Zombie::zombie = zombie;
	BucketHead_Zombie::zdamage = zdamage;
	BucketHead_Zombie::zlife = zlife;
	PoleVaulting_Zombie::zspeed = zspeed;
	PoleVaulting_Zombie::jump = jump;
	this->unic_per_round = unic;
	this->random_appearance = timp;

}

Super_Zombie::Super_Zombie()
{

	BucketHead_Zombie::zombie = "ZS";
	BucketHead_Zombie::zdamage = 50;
	BucketHead_Zombie::zlife = 700;
	PoleVaulting_Zombie::zspeed = 3;
	PoleVaulting_Zombie::jump = 1;
	this->unic_per_round = 1;
	this->random_appearance = 10;

}

void Super_Zombie::set_unic_per_round(int unic)
{

	this->unic_per_round = unic;

}

void Super_Zombie::set_random_appearance(int timp)
{

	this->random_appearance = timp;

}

int Super_Zombie::get_unic_per_round()
{

	return this->unic_per_round;

}

int Super_Zombie::get_random_appearance()
{

	return this->random_appearance;

}

void Super_Zombie::print()
{

	cout << "Zombie : \t\t\t" << BucketHead_Zombie::get_zombie() << "\nLife : \t\t\t" << BucketHead_Zombie::get_zlife() << "\nSpeed : \t\t\t" << PoleVaulting_Zombie::get_zspeed() << "\nDamage : \t\t\t" << BucketHead_Zombie::get_zdamage() << "\nJump : \t\t\t" << PoleVaulting_Zombie::get_jump() << "\nUnic per runda : \t\t\t" << this->unic_per_round << "\nRandom appearance : \t\t\t" << this->random_appearance << "\n\n\n";

}

//ostream& operator<< (ostream& out, const Super_Zombie &ob)
//{
//
//	out << "Zombie : \t\t\t" << ((BucketHead_Zombie)ob).get_zombie() << "\nLife : \t\t\t" << ob.get_zlife() << "\nSpeed : \t\t\t" << ob.get_zspeed() << "\nDamage : \t\t\t" << ob.get_zdamage() << "\nJump : \t\t\t" << ob.get_jump() << "\nUnic per runda : \t\t\t" << ob.get_unic_per_round() << "\nRandom appearance : \t\t\t" << ob.get_random_appearance() << "\n\n\n";
//
//	return out;
//
//}

Super_Zombie::~Super_Zombie()
{

}