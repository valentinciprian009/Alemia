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
#include "Proiectil.h"

using namespace std;

Proiectil::Proiectil()
{

	this->proiectil = "..";
	this->speed =  2;
	this->x = -1;
	this->y = 1;

}

Proiectil::Proiectil(string proiectil, int speed)
{

	this->proiectil = proiectil;
	this->speed = speed;
	this->x = -1;
	this->y = -1;

}

void Proiectil::set_proiectil(string proiectil)
{

	this->proiectil = proiectil;

}

void Proiectil::set_speed(int speed)
{

	this->speed = speed;

}

int Proiectil::get_speed()
{

	return this->speed;

}

string Proiectil::get_proiectil()
{

	return this->proiectil;

}

void Proiectil::set_x(int x)
{

	this->x = x;

}

void Proiectil::set_y(int y)
{

	this->y = y;

}

int Proiectil::get_x()
{
	return this->x;
}

int Proiectil::get_y()
{
	return this->y;
}

Proiectil::~Proiectil()
{

}