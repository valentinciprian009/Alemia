#include "BucketHeadZombie.h"
#include "ConsoleOutput.h"
#include "Terrain.h"
#include "GameSession.h"

BucketHeadZombie::BucketHeadZombie()
{
	this->health = 250;
}

void BucketHeadZombie::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(9 + 6 * x, 20 + 15 * y + 7, 96) << L"▲▲";
	conOut(10 + 6 * x, 20 + 15 * y + 7, 176) << L"◂○";
	conOut(10 + 6 * x, 20 + 15 * y + 5, 1) << " "; conOut(10 + 6 * x, 20 + 15 * y + 10, 1) << " ";
	conOut(11 + 6 * x, 20 + 15 * y + 6, 1) << "    ";
	conOut(12 + 6 * x, 20 + 15 * y + 7, 1) << "  ";
	conOut(13 + 6 * x, 20 + 15 * y + 5, 1) << "  "; conOut(13 + 6 * x, 20 + 15 * y + 9, 1) << "  ";

}

std::string BucketHeadZombie::identity()
{
	return "BucketHeadZombie";
}

void BucketHeadZombie::useSkill()
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

GameObject* BucketHeadZombie::clone()
{
	BucketHeadZombie* monster = new BucketHeadZombie;
	monster->health = this->health;
	monster->x = this->x;
	monster->y = this->y;
	return monster;
}

