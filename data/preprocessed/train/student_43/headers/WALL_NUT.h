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

using namespace std;

class WALL_NUT :	public Plants
{



public:
	
	WALL_NUT();

	WALL_NUT(string planta, int resistance, int cost, int delay);
	
	~WALL_NUT();

};