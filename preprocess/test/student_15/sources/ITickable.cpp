#define _CRT_SECURE_NO_WARNINGS
#include "ITickable.h"

std::string ITickable::curentTime()
{
	auto x = std::chrono::system_clock::to_time_t(
		std::chrono::system_clock::now()
	);
	return std::string(std::ctime(&x));
}

void ITickable::updateTime()
{
	if (!tickEnabled)
	{
		previous = std::chrono::steady_clock::now();
		return;
	}

	present = std::chrono::steady_clock::now();
	int scurs = std::chrono::duration_cast<std::chrono::milliseconds>(present - previous).count();
	if (scurs + leftover > T)
	{
		previous = present;
		for (leftover += scurs; leftover > T; leftover -= T)
			tickAction();
	}
}

void ITickable::changePeriod(int period)
{
	T = period;
}

void ITickable::resetTime()
{
	previous = present = std::chrono::steady_clock::now();
}

ITickable::ITickable(int period, bool tick)
{
	tickEnabled = tick;
	leftover = 0;
	T = period;
	previous = std::chrono::steady_clock::now();
}
