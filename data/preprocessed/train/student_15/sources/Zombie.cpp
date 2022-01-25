#include "Zombie.h"
#include "GameManager.h"
#include "Slide.h"

using namespace Arena;

void Arena::BasicZombie::tickAction()
{
	int prv = int(gx - 2 / float(CELLX));
	if (parent->empty(gy, prv))
	{
		cx--;
		gx -= 1 / float(CELLX);
		if (gx < 2 / float(CELLX))
			parent->gameOver();
	}
	else
		parent->plants[gy][prv]->damage();
}

Arena::BasicZombie::BasicZombie(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int id) : 
	ITickable(zombies[id].speed, false), IGameElement(pr, conout)
{
	gy = y;
	gx = TERENX + 2 / float(CELLX);
	cy = HLINE + 2 + CELLY * gy;
	cx = VLINE + 1 + CELLX*TERENX + 2;
	hp = zombies[id].maxHP;
	this->id = id;
	eff = new SlownessEffect(this);
}

void Arena::BasicZombie::startMoving()
{
	tickEnabled = true;
}

Arena::BasicZombie::~BasicZombie()
{
	delete eff;
	parent->addScore(zombies[id].points);
	Slide::clearZone(conOut, cx, cy, cx + 7, cy + CELLY - 2);
	std::string s = "A ";
	s += zombies[id].name;
	s += " from row ";
	s += '0' + gy + 1;
	s += " died after making it through";
	s += (TERENX + 2 / float(CELLX) - gx);
	s += " cells.";
	parent->log(s);
}

void Arena::BasicZombie::update()
{
	updateTime();
	eff->updateTime();
}

void Arena::BasicZombie::draw()
{
	Slide::drawAsciiArt(
		zombies[id].filename,
		conOut, cy, cx
	);
}

bool Arena::BasicZombie::active()
{
	return hp > 0;
}

bool Arena::BasicZombie::insideCell(int pos)
{
	return (float(pos) - 0.5 <= gx && gx <= float(pos) + 1.0);
}

void Arena::BasicZombie::damage(int d)
{
	hp -= d;
}

void Arena::BasicZombie::slowDown()
{
	eff->apply();
}

void Arena::SlownessEffect::timerAction()
{
	parent->changePeriod(BasicZombie::zombies[parent->id].speed);
}

void Arena::SlownessEffect::apply()
{
	parent->changePeriod(BasicZombie::zombies[parent->id].speed / 2);
	restart();
}
