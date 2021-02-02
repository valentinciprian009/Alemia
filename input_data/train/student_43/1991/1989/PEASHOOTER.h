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
#include "Plants.h"
#include "Proiectil.h"
#include "Pea.h"

using namespace std;

class PEASHOOTER :	public Plants
{

	class Pea ob;
	int cadenta_tragere;

public:

	void set_obiect(Pea &obiect);

	Pea get_obiect();

	void set_cadenta_tragere(int cadenta_tragere);

	int get_cadenta_tragere();

	PEASHOOTER(string planta, int cadenta_tragere, int cost, int delay, int resistance);
	
	PEASHOOTER();

	~PEASHOOTER();

};