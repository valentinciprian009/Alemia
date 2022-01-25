#include "Peashooter.h"
#include "ConsoleOutput.h"
#include "Terrain.h"
#include <chrono>

using namespace std::chrono;

Peashooter::Peashooter()
{
	setPrice(50);
	setStrength(5);
}

void Peashooter::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * x, 20 + 15 * y + 7, 208) << L"○▸";
	conOut(11 + 6 * x, 20 + 15 * y + 6, 1) << "    ";
	conOut(12 + 6 * x, 20 + 15 * y + 7, 1) << "  ";
	conOut(13 + 6 * x, 20 + 15 * y + 5, 1) << "      ";

	projectile.x = x;
	projectile.y = y;
	setX(x);
	setY(y);
}

void Peashooter::draw(int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * y, 9, 208) << L"○▸";
	conOut(11 + 6 * y, 8, 1) << "    ";
	conOut(12 + 6 * y, 9, 1) << "  ";
	conOut(13 + 6 * y, 7, 1) << "      ";
}

std::string Peashooter::identity()
{
	return "Peashooter";
}

void Peashooter::useSkill()
{
	if (duration_cast<milliseconds>(steady_clock::now() - this->getTimer()).count() >= 3000)
	{
		projectile.y = this->getY();
		projectile.x = this->getX();
		this->resetTimer();
	}

	Terrain& terrain = Terrain::getInstance();
	if (duration_cast<milliseconds>(steady_clock::now() - projectile.timer).count() >= 200)
	{
		projectile.timer = steady_clock::now();
		if (projectile.y > 9)
			return;
		terrain.redraw(projectile.x, projectile.y);
		projectile.draw(projectile.x , projectile.y + 1);

		if (terrain.isZombie(projectile.x, projectile.y))
		{
			terrain.damage(projectile.x, projectile.y, 15);
			projectile.draw(projectile.x, projectile.y);
			terrain.redraw(projectile.x, projectile.y);
			projectile.y = this->getY();
			this->resetTimer();
			return;
		}
		if (terrain.isZombie(projectile.x, projectile.y - 1))
		{
			terrain.damage(projectile.x, projectile.y-1, 15);
			terrain.redraw(projectile.x, projectile.y);
			projectile.y = this->getY();
			this->resetTimer();
			return;
		}
	}
}
