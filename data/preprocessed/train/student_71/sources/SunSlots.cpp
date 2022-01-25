#include "SunSlots.h"
#include "ConsoleOutput.h"
#include <cstdlib>
#include <time.h>
#define SUNSLOT_0_ROW					3
#define SUNSLOT_0_COL					28

SunSlots* SunSlots::instance = NULL;

SunSlots::SunSlots()
{
	for (int i = 0; i < 9; i++)
		data[i] = false;
}

SunSlots::~SunSlots()
{
	for (int i = 0; i < 9; i++)
		data[i] = false;
}

SunSlots& SunSlots::getInstance()
{
	if (!SunSlots::instance)
		SunSlots::instance = new SunSlots;
	return *SunSlots::instance;
}

void SunSlots::destroyInstance()
{
	delete instance;
}

void SunSlots::spawnSun()
{
	// Check if there is an empty slot
	int temp;
	for (temp = 0; temp < 9; temp++)
		if (!data[temp])
			break;
	// If there are not, return
	if (temp == 9)
		return;

	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	srand(time(NULL));
	int x = rand() % 9;

	// Pick an empty slot
	while (data[x] == true)
		x = rand() % 9;

	// Draw the sun
	conOut(SUNSLOT_0_ROW - 2, SUNSLOT_0_COL - 1 + 15 * x, 230) << "|";
	conOut(SUNSLOT_0_ROW - 1, SUNSLOT_0_COL - 3 + 15 * x, 230) << "\\ _ /";
	conOut(SUNSLOT_0_ROW, SUNSLOT_0_COL - 5 + 15 * x, 230) << "-= (_) =-";
	conOut(SUNSLOT_0_ROW + 1, SUNSLOT_0_COL - 3 + 15 * x, 230) << "/   \\";
	conOut(SUNSLOT_0_ROW + 2, SUNSLOT_0_COL - 1 + 15 * x, 230) << "|";

	data[x] = true; // mark the slot full
}

void SunSlots::clearSlot(int x)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(SUNSLOT_0_ROW - 2, SUNSLOT_0_COL - 1 + 15 * x) << " ";
	conOut(SUNSLOT_0_ROW - 1, SUNSLOT_0_COL - 3 + 15 * x) << "     ";
	conOut(SUNSLOT_0_ROW, SUNSLOT_0_COL - 5 + 15 * x) << "         ";
	conOut(SUNSLOT_0_ROW + 1, SUNSLOT_0_COL - 3 + 15 * x) << "     ";
	conOut(SUNSLOT_0_ROW + 2, SUNSLOT_0_COL - 1 + 15 * x) << " ";

	data[x] = false; // mark the slot empty
}

bool SunSlots::isSun(int x)
{
	return data[x];
}

