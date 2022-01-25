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

using namespace std;

class Resource
{

protected:

	string resursa;
	int aparitie;
	int valoare;
	int timp;
	int x;
	int y;


public:

	Resource();

	Resource(string resursa, int aparitie, int valoare, int timp);

	void set_string(string resursa);

	void set_aparitie(int aparitie);

	void set_valoare(int valoare);

	void set_timp(int timp);

	void set_x(int x);

	void set_y(int y);

	string get_string();

	int get_aparitie();

	int get_timp();
	
	int get_valoare();

	int get_x();

	int get_y();

	string get_string() const { return this->resursa; };

	int get_aparitie() const { return this->aparitie; };

	int get_timp() const { return this->timp; };

	int get_valoare() const { return this->valoare; };

	int get_x() const { return this->x; };

	int get_y() const { return this->y; };

	~Resource();

};