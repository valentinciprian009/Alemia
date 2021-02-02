#include "Cadran.h"

bool Cadran::testTime(int time)
{
	auto callTime = steady_clock::now();
	if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
	{
		trackTime = callTime;
		return true;
	}
	return false;
}