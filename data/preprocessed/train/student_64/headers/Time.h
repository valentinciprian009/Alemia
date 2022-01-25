#pragma once
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std::chrono;
class Time
{
private:
	bool set;
	 int durat;
public:
	void set_time()
	{
		set = 1;
	}
	void update()
	{
		static auto begin = steady_clock::now();
		auto end = steady_clock::now();
		durat = duration_cast<seconds>(end - begin).count();
		if (set)
		{
			begin = end;
			set = 0;
		}
	}
	 int durata()
	{
		return durat;
	}
};

