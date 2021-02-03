#include "ITimer.h"

void ITimer::updateTime()
{
	if (activ)
		return;
	present = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(present - previous).count() > P)
	{
		timerAction();
		activ = true;
	}
}

ITimer::ITimer(int time, bool start)
{
	P = time;
	if (start)
		restart();
	else
		activ = true;
}

bool ITimer::timerDone()
{
	return activ;
}

void ITimer::restart()
{
	activ = false;
	present = previous = std::chrono::steady_clock::now();
}


