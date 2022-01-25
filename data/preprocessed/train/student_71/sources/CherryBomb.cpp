#include "CherryBomb.h"
#include "ConsoleOutput.h"
#include "Terrain.h"
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

CherryBomb::CherryBomb()
{
	setPrice(150);
	setStrength(10);
}

void CherryBomb::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * x, 20 + 15 * y + 7, 1) << " ";
	conOut(11 + 6 * x, 20 + 15 * y + 6, 1) << " "; conOut(11 + 6 * x, 20 + 15 * y + 7, 1) << "  ";
	conOut(12 + 6 * x, 20 + 15 * y + 3, 64) << L" ▾▾ "; conOut(12 + 6 * x, 20 + 15 * y + 8, 64) << L" ▾▾ ";
	conOut(13 + 6 * x, 20 + 15 * y + 3, 64) << L" ︠︡ "; conOut(13 + 6 * x, 20 + 15 * y + 8, 64) << L" ︠︡ ";
	setX(x);
	setY(y);
}

void CherryBomb::draw(int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * y, 9, 1) << " ";
	conOut(11 + 6 * y, 8, 1) << " "; conOut(11 + 6 * y, 9, 1) << "  ";
	conOut(12 + 6 * y, 5, 64) << L" ▾▾ "; conOut(12 + 6 * y, 10, 64) << L" ▾▾ ";
	conOut(13 + 6 * y, 5, 64) << L" ︠︡ "; conOut(13 + 6 * y, 10, 64) << L" ︠︡ ";
}

std::string CherryBomb::identity()
{
	return "CherryBomb";
}

void CherryBomb::useSkill()
{
	
	if (duration_cast<milliseconds>(steady_clock::now() - this->skillTimer).count() < 1000)
		return;
	Terrain& terrain = Terrain::getInstance();
	for (int i = this->getX() - 1; i < this->getX() + 2; i++)
		for (int j = this->getY() - 1; j < this->getY() + 2; j++)
		{
			if ((i < 0) || (i >= 5) || (j < 0) || (j >= 9) || ((i == this->getX())&&(j == this->getY())))
				continue;
			if (terrain.isZombie(i, j))
				terrain.damage(i, j, 200);
		}

	terrain.destroy(this->getX(), this->getY());

}
