#include"SunGround.h"

void SunGround::createSuns()
{
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	srand(time(NULL));
	int fullSun = 1;
	for (auto sun : sunRow)
	{
		fullSun *= sun.getType();
	}
	if (((float)duration_cast<seconds>(end - begin).count() > timeInterval) && (fullSun == 0))
	{
		begin = end;
		int sunLocation = rand() % sunRow.size();
		while (sunRow[sunLocation].getType() == 6)
		{
			sunLocation = rand() % sunRow.size();
		}
		sunRow[sunLocation].changeType(6);
	}
}

int SunGround::takeSun()
{
	ConsoleEvent& action = consoleIn.getUserActions();
	for (int i = 0; i < sunRow.size(); i++)
	{
		if ((sunRow[i].getType() == 6) && sunRow[i].checkInCell(action))
		{
			sunRow[i].clearCell();
			sunRow[i].changeType(0);
			Log::getInstance().write("Sun collected!");
			return 10;
		}
	}
	return 0;
}

void SunGround::print()
{
	createSuns();
	for (auto sun : sunRow)
		sun.print();
}