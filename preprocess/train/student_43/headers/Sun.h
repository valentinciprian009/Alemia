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
#include "Resource.h"

using namespace std;

class Sun : public Resource
{

	
public:

	Sun();

	Sun(string resursa, int valoare, int timp, int aparitie);

	~Sun();

};