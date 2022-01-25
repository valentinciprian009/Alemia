#pragma once
#include "ConsoleOutput.h"
#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

class Cadran
{
private:
	int lineNumber;
	int colNumber;
	steady_clock::time_point trackTime;
public:
	Cadran() { this->lineNumber = 0; this->colNumber = 0; };
	Cadran(int x, int y) { this->lineNumber = y; this->colNumber = x; trackTime = steady_clock::now(); };
	~Cadran() {};
	int getLineNumber() { return this->lineNumber; };
	int getColNumber() { return this->colNumber; };
	bool testTime(int time);
};