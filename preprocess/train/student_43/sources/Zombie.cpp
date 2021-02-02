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

Zombie::Zombie(string zombie, int zspeed, int zdamage, int zlife)
{

	this->zombie = zombie;
	this->zdamage = zdamage;
	this->zlife = zlife;
	this->zspeed = zspeed;

}

Zombie::Zombie()
{

	this->zombie = "ZZ";
	this->zdamage = 25;
	this->zlife = 300;
	this->zspeed = 1;

}

void Zombie::set_zspeed(int zpeed)
{

	this->zspeed = zspeed;

}

void Zombie::set_zombie(string zombie)
{

	this->zombie = zombie;

}

void Zombie::set_zlife(int zlife)
{

	this->zlife = zlife;

}

void Zombie::set_zdamage(int zdamage)
{

	this->zdamage = zdamage;

}

void Zombie::set_x(int x)
{
	this->x = x;
}

void Zombie::set_y(int y)
{
	this->y = y;
}

string Zombie::get_zombie()
{

	return this->zombie;

}

int Zombie::get_zdamage()
{

	return this->zdamage;

}

int Zombie::get_zlife()
{

	return this->zlife;

}

int Zombie::get_zspeed()
{

	return this->zspeed;

}

int Zombie::get_x()
{
	return this->x;
}

int Zombie::get_y()
{
	return this->y;
}

void Zombie::print()
{

	cout << "Zombie : \t\t\t" << this->zombie << "\nLife : \t\t\t" << this->zlife << "\nSpeed : \t\t\t" << this->zspeed << "\nDamage : \t\t\t" << this->zdamage << "\n\n\n";

}

//ostream &operator<<(ostream &out, const Zombie &ob)
//{
//
//	out << "Zombie : \t\t\t" << ob.get_zombie() << "\nLife : \t\t\t" << ob.get_zlife() << "\nSpeed : \t\t\t" << ob.get_zspeed() << "\nDamage : \t\t\t" << ob.get_zdamage() << "\n\n\n";
//
//	return out;
//
//}

Zombie::~Zombie()
{

	//if (this->zombie)
	//	delete[] this->zombie;

}