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
#include "WALL_NUT.h"

using namespace std;

WALL_NUT::WALL_NUT() : Plants("PW", 400, 8, 5)
{

}

WALL_NUT::WALL_NUT(string planta, int resistance, int cost, int delay) : Plants(planta, resistance, cost, delay)
{

}

WALL_NUT::~WALL_NUT()
{

}