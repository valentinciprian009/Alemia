#include "Zombie.h"
#include "Terrain.h"
#include "Scoreboard.h"


void Zombie::damage(int x, bool slowed)
{
	health -= x;
	if ((!this->slowed)&&(slowed))
	{
		this->slowed = true;
		timePeriod += 1500;
		slowedTimer = steady_clock::now();
	}

	if (!isAlive())
	{
		Terrain& terrain = Terrain::getInstance();
		terrain.destroy(this->getX(), this->getY());
		Scoreboard& score = Scoreboard::getInstance();
		score.zombieKilled();
		score.update();
	}
}

bool Zombie::isAlive()
{
	if (health>0)
		return true;
	return false;
}

