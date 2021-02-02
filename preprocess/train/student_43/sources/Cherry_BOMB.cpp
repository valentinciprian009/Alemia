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
#include "Plants.h"
#include "Cherry_BOMB.h"

using namespace std;

Cherry_BOMB::Cherry_BOMB(string planta, int cost, int delay, int resistance, int power, int time_bomb, int valability) : Plants(planta, resistance, cost, delay)
{

	this->time_bomb = time_bomb;
	this->power = power;
	this->valability = valability;

}

Cherry_BOMB::Cherry_BOMB() : Plants("PC", 0, 5, 11)
{

	this->time_bomb = 5;
	this->power = 200;
	this->valability = 1;

}

void Cherry_BOMB::set_time_bomb(int time_bomb)
{

	this->time_bomb = time_bomb;

}

void Cherry_BOMB::set_power(int power)
{
	this->power = power;
}

void Cherry_BOMB::set_valability(int valability)
{
	this->valability = valability;
}

int Cherry_BOMB::get_time_bomb()
{
	return this->time_bomb;
}

int Cherry_BOMB::get_valability()
{
	return this->valability;
}

int Cherry_BOMB::get_power()
{
	return this->power;
}

Cherry_BOMB::~Cherry_BOMB()
{

}