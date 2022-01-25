#pragma once
#include <time.h>
#include <chrono>
#include <ctime>
#include <string>

class ITickable
{
private:
	typedef std::chrono::time_point<std::chrono::steady_clock> timer;

	int T;
	int leftover;
	timer previous;
	timer present;

public:
	static std::string curentTime();

protected:
	void updateTime();

	void changePeriod(int period);
	bool tickEnabled;

	void resetTime();

	virtual void tickAction() = 0;


public:
	ITickable(int period, bool tick = true);

};

