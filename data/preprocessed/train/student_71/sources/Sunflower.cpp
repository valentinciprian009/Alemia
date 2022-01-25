#include "Sunflower.h"
#include "ConsoleOutput.h"
#include "SunSlots.h"
#include <chrono>

using namespace std::chrono;

Sunflower::Sunflower()
{
	setPrice(50);
	setStrength(3);
}

void Sunflower::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * x, 20 + 15 * y + 6, 224) << "    ";
	conOut(11 + 6 * x, 20 + 15 * y + 5, 224) << "  "; conOut(96) << L"◦◦"; conOut(224) << "  ";
	conOut(12 + 6 * x, 20 + 15 * y + 6, 224) << "    ";
	setX(x);
	setY(y);
}

void Sunflower::draw(int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 *y, 8, 224) << "    ";
	conOut(11 + 6 * y, 7, 224) << "  "; conOut(96) << L"◦◦"; conOut(224) << "  ";
	conOut(12 + 6 * y, 8, 224) << "    ";
}

std::string Sunflower::identity()
{
	return "Sunflower";
}

void Sunflower::useSkill()
{
	if (duration_cast<milliseconds>(steady_clock::now() - skillTimer).count() >= 5000)
	{
		skillTimer = std::chrono::steady_clock::now();
		SunSlots& sun = SunSlots::getInstance();
		sun.spawnSun();
	}
}
