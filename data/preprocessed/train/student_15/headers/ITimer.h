#pragma once
#include <time.h>
#include <chrono>
#include <ctime>
#include <string>

class ITimer
{
private:
	typedef std::chrono::time_point<std::chrono::steady_clock> timer;
	
	timer present;
	timer previous;

	int P;
	bool activ;
protected:
	virtual void timerAction() = 0;

	bool timerDone();
	void restart();
public:
	ITimer(int time, bool start = true);


	void updateTime();
};

