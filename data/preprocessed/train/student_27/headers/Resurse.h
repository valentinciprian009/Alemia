#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <chrono>
#include<thread>
using namespace std::this_thread;
using namespace std::chrono;
class Resurse
{
	int vect[8];
public:
	Resurse();
	~Resurse();
	void creeaza_resurse();
	void numara_resurse();
};

