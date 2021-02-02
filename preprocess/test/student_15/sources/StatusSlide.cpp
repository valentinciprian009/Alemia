#include "StatusSlide.h"

StatusSlide::StatusSlide(int st)
	: Slide(true)
{
	status = st;
	if (st == GAME_OVER)
	{
		conOut(1, 1) << "Game over";
		buttons.push_back(new StatusButton(this, 0, RESET, "Retry level"));
		buttons.push_back(new StatusButton(this, 1, MENU | SAVE, "Save and go to menu"));
	}
	else if (st == CLEARED)
	{
		conOut(1, 1) << "Level cleared";
		buttons.push_back(new StatusButton(this, 0, RESET, "Retry level"));
		buttons.push_back(new StatusButton(this, 1, RESET | NEXTLVL, "Next level"));
		buttons.push_back(new StatusButton(this, 2, MENU | SAVE, "Save and go to menu"));
	}
	else if (st == PAUSED)
	{
		conOut(1, 1) << "Game paused";
		buttons.push_back(new StatusButton(this, 0, RESET, "Restart level"));
		buttons.push_back(new StatusButton(this, 1, NOTHING, "Continue level"));
		buttons.push_back(new StatusButton(this, 2, MENU, "Quit and go to menu"));
	}
	else
	{
		conOut(1, 1) << "Game ended";
	}
	
	for (auto it : buttons)
		it->draw(conOut);
}

void StatusSlide::setResponse(int r)
{
	res = r;
}

int StatusSlide::response()
{
	return res;
}

void StatusSlide::update()
{
	for (std::string s = conIn.getUserActions(); s != ""; s = conIn.getUserActions())
	{
		for (auto it : buttons)
			it->click(s);
	}
}

void StatusSlide::reinit()
{
}

void StatusButton::pushFunction()
{
	StatusSlide* pr = static_cast<StatusSlide*>(parent);
	pr->active = false;
	pr->setResponse(act);
}

StatusButton::StatusButton(Slide* prnt, int index, int action, std::string txt) : Button(prnt)
{
	act = action;
	text = txt;
	x = 5;
	y = 3 + index * 4;
	width = 20;
	height = 1;
}
