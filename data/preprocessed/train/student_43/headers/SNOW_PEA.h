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
#include "Pea.h"
#include "Frozen_Pea.h"

using namespace std;

class SNOW_PEA : public Plants
{

	class Frozen_Pea obiect;
	int cadenta_tragere;

public:

	SNOW_PEA();

	SNOW_PEA(string planta, int resistance, int cost, int delay, int cadenta_tragere);
	
	~SNOW_PEA();

	int get_cadenta_tragere();

	int get_cadenta_tragere() const { return this->cadenta_tragere; };

	void set_cadenta_tragere(int cadenta_tragere);

	void set_obiect(Frozen_Pea &obiect);

	Frozen_Pea get_obiect();

};