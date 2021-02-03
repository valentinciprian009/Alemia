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
#include "Resource.h"

using namespace std;

Resource::Resource()
{

	this->aparitie = 0;
	this->timp = 1;
	this->resursa = "RR";
	this->valoare = 1;

}

Resource::Resource(string resursa, int aparitie, int valoare, int timp)
{

	this->resursa = resursa;
	this->aparitie = aparitie;
	this->valoare = valoare;
	this->timp = timp;
	this->x = 1;
	this->y = -1;

}

void Resource::set_string(string resursa)
{

	this->resursa = resursa;

}

void Resource::set_aparitie(int aparitie)
{

	this->aparitie = aparitie;

}

void Resource::set_valoare(int valoare)
{

	this->valoare = valoare;

}

void Resource::set_timp(int timp)
{

	this->timp = timp;

}

void Resource::set_x(int x = 1)
{

	this->x = x;

}

void Resource::set_y(int y)
{

	this->y = y;

}

string Resource::get_string()
{

	return this->resursa;

}

int Resource::get_aparitie()
{
	return this->aparitie;
}

int Resource::get_timp()
{
	return this->timp;
}

int Resource::get_valoare()
{
	return this->valoare;
}

int Resource::get_x()
{
	return this->x;
}

int Resource::get_y()
{
	return this->y;
}

Resource::~Resource()
{

}