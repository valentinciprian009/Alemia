#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std::chrono;
using namespace std;


class Sun
{
public:
	Sun();

	void drawSun();

	void appearInRandomPlace();

	int nrSun();

	~Sun();
};

