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
#include "Sun.h"
#include "Pea.h"

using namespace std;

class SUNFLOWER :	public Plants
{

	class Sun ob;

public:
	
	SUNFLOWER();

	SUNFLOWER(int cost, int delay, string planta, int resistance);
	
	~SUNFLOWER();

	void set_obiect(Sun &obiect);

	Sun get_obiect();

};

