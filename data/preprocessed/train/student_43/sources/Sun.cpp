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
#include "Sun.h"

using namespace std;

Sun::Sun() : Resource("SS", 0, 2, 2)
{

}

Sun::Sun(string resursa, int valoare, int timp, int aparitie) : Resource(resursa, aparitie, valoare, timp)
{

}

Sun::~Sun()
{

}