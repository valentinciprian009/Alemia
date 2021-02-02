#pragma once

#include <time.h>
#include <chrono>

class Pea
{
private:
	int x0, y0;
	int xp = -1;
	int interval = 1000;
	std::chrono::time_point<std::chrono::steady_clock> begin;
	std::chrono::time_point<std::chrono::steady_clock> end;

public:
	Pea(int x, int y);
	int get_x();
	~Pea();
};

