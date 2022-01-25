#include "PoleVaultingZombie.h"
#include "ConsoleOutput.h"
#include "Terrain.h"
#include "GameSession.h"

PoleVaultingZombie::PoleVaultingZombie()
{
	this->health = 150;
	this->timePeriod = 1000;
}

void PoleVaultingZombie::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10 + 6 * x, 20 + 15 * y + 7, 176) << L"◂○";
	conOut(10 + 6 * x, 20 + 15 * y + 5, 80) << " "; conOut(10 + 6 * x, 20 + 15 * y + 10, 80) << " ";
	conOut(11 + 6 * x, 20 + 15 * y + 6, 1) << "    ";
	conOut(12 + 6 * x, 20 + 15 * y + 7, 1) << "  ";
	conOut(13 + 6 * x, 20 + 15 * y + 5, 1) << "  "; conOut(13 + 6 * x, 20 + 15 * y + 9, 1) << "  ";

}

std::string PoleVaultingZombie::identity()
{
	return "PoleVaultingZombie";
}

void PoleVaultingZombie::useSkill()
{
	Terrain& terrain = Terrain::getInstance();
	if (this->slowed)
		if ((duration_cast<milliseconds>(steady_clock::now() - slowedTimer).count() >= 3000))
		{
			this->slowed = false;
			timePeriod -= 1500;
		}

	if (duration_cast<milliseconds>(steady_clock::now() - moveTimer).count() >= timePeriod)
	{
		if (this->getY() == 0)
		{
			GameSession& session = GameSession::getInstance();
			session.terminate(-1);
			return;
		}

		if (terrain.isEmpty(this->getX(), this->getY() - 1))
		{
			moveTimer = steady_clock::now();
			terrain.move(this, 1);
		}

		if(terrain.isPlant(this->getX(),this->getY()-1))
			if (!jumped)
			{
				moveTimer = steady_clock::now();
				jumped = true;
				this->timePeriod = 2000;
				terrain.move(this, 2);
			}
	}

	if (duration_cast<milliseconds>(steady_clock::now() - skillTimer).count() >= 2000)
	{
		if (this->getY() != 0)
			if (terrain.isPlant(this->getX(), this->getY() - 1))
			{
				terrain.damage(this->getX(), this->getY() - 1);
				skillTimer = steady_clock::now();
			}
	}
}

GameObject* PoleVaultingZombie::clone()
{
	PoleVaultingZombie* monster = new PoleVaultingZombie;
	monster->health = this->health;
	monster->x = this->x;
	monster->y = this->y;
	monster->jumped = this->jumped;
	monster->timePeriod = this->timePeriod;
	return monster;
}
