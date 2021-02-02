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

using namespace std;

BucketHead_Zombie::BucketHead_Zombie() : Zombie("ZB", 1, 25, 700)
{

}

BucketHead_Zombie::BucketHead_Zombie(string zombie, int zspeed, int zlife, int zdamage) : Zombie(zombie, zspeed, zdamage, zlife)
{

}

void BucketHead_Zombie::print()
{

	cout << "Zombie : \t\t\t" << this->get_zombie() << "\nLife : \t\t\t" << this->get_zlife() << "\nSpeed : \t\t\t" << this->get_zspeed() << "\nDamage : \t\t\t" << this->get_zdamage() << "\n\n\n";

}

//ostream &operator<<(ostream &out, const BucketHead_Zombie &ob)
//{
//
//	out << "Zombie : \t\t\t" << ob.get_zombie() << "\nLife : \t\t\t" << ob.get_zlife() << "\nSpeed : \t\t\t" << ob.get_zspeed() << "\nDamage : \t\t\t" << ob.get_zdamage() << "\n\n\n";
//
//	return out;
//
//}

BucketHead_Zombie::~BucketHead_Zombie()
{

}