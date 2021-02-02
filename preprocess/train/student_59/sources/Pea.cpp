#include "Pea.h"
#include "ConsoleOutput.h"


Pea::Pea(int x, int y)
{
	y0 = y;
	x0 = x;
	begin = std::chrono::steady_clock::now();
}

int Pea::get_x()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	end = std::chrono::steady_clock::now();
	int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	int x = x0 + time / interval;
	conOut(9 + 5 * y0, 34 + 15 * x) << "-";
	if (xp != -1 && xp != x)
		conOut(9 + 5 * y0, 34 + 15 * xp) << " ";
	xp = x;
	return x;
}

Pea::~Pea()
{
}
