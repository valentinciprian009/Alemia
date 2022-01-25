#include "ArenaSlide.h"

using namespace Arena;

ArenaButton::ArenaButton(Slide* pr, int cx, int cy) : Button(pr)
{
	width = CELLX - 1;
	height = CELLY - 1;
	x = VLINE + 1 + CELLX * cx;
	y = HLINE + 1 + CELLY * cy;
	text = "";
	gx = cx, gy = cy;
}

int Arena::ArenaButton::gridX() { return gx; }
int Arena::ArenaButton::gridY() { return gy; }

void ArenaButton::pushFunction()
{
	ArenaSlide* th = static_cast<ArenaSlide*>(parent);
	if (th->state < 100)
		return;
	if (!th->gman->empty(gy, gx))
		return;

	th->suns -= BasicPlant::plants[th->state - 100].cost;
	th->gman->addPlant(th->state - 100, gy, gx);
	th->state = 0;
	Slide::clearZone(th->conOut, VLINE + 1, HLINE + 1);
	th->gman->draw(th->conOut);
}

void PlantButton::pushFunction()
{
	ArenaSlide* th = static_cast<ArenaSlide*>(parent);
	if (th->suns < cost)
		return;
	if (th->state == 100 + id)
	{
		th->state = 0;
		Slide::clearZone(th->conOut, VLINE + 1, HLINE + 1);
		th->gman->draw(th->conOut);
		return;
	}
	th->state = 100 + id;
	for (auto it : th->teren)
		if(th->gman->empty(it->gridY(), it->gridX()))
			it->draw(th->conOut);
}

PlantButton::PlantButton(Slide* pr, PlantInfo pi) : Button(pr), PlantInfo(pi)
{
	text = name;
	x = 2;
	y = HLINE + 1 + CELLY * id;
	height = CELLY;
	width = VLINE - 4;
}

void PlantButton::draw(UserInterface::ConsoleOutput conOut)
{
	Slide::drawAsciiArt(filename, conOut, y, x+2);
	//Slide::drawHline(conOut, y + height - 2, x, x + width - 1, 'v');
	conOut(y + height - 1, x) << text;
	conOut(y + height - 1, x + width - 5) << " SUNS";
	conOut(y + height - 1, x + width - (cost > 9 ? 7 : 6)) << cost;
}

