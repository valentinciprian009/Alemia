#include "ArenaSlide.h"
#include <stdlib.h>
#include "ZombieDispenser.h"
#include "StatusSlide.h"

using namespace Arena;

void Arena::ArenaSlide::printNumber(int number, int y, int x)
{
	int cf = 0;
	if (number == 0)
		cf = 1;
	else
		for (int n = number; n > 0; n /= 10)
			cf++;
	conOut(y, x) << number;
	conOut(y, x + cf) << " ";
}

ArenaSlide::ArenaSlide(User* usr) : Slide(true)
{
	user = usr;
	gman = new GameManager(this);
	rman = ResourceManager::getInstance();
	zman = new ZombieDispenser(gman, usr->level());

	for (auto it : BasicPlant::plants)
		menu.push_back(new PlantButton(this, it));

	for(int i=0; i<gman->terenY(); i++)
		for (int j = 0; j < TERENX; j++)
			teren.push_back(new ArenaButton(this, j, i));

	reinit();
}

void ArenaSlide::update()
{
	rman->update(conOut);
	gman->update();
	if (next != nullptr)
		return;
	
	zman->update();
	gman->draw(conOut);


	if (gman->nozombies() && zman->done()) {
		user->addScore(gman->score());
		next = new StatusSlide(StatusSlide::CLEARED);
		return;
	}

	for (std::string s = conIn.getUserActions(); s != ""; s = conIn.getUserActions())
	{
		rman->click(s, suns, conOut);
		
		for (auto it : menu)
			it->click(s);

		if(state >= 100)
		for (auto it : teren)
			it->click(s);
	}

	printNumber(user->score(), 2, 15);
	
	printNumber(user->level(), 3, 9);
	printNumber(gman->score(), 4, 9);
	printNumber(suns, 3, 19);
	printNumber(gman->wave(), 4, 19);	
}

void Arena::ArenaSlide::reinit()
{
	if (next != nullptr)
	{
		StatusSlide* nxt = static_cast<StatusSlide*>(next);
		saveuser = (nxt->response() & StatusSlide::SAVE);
		if (nxt->response() & StatusSlide::NEXTLVL)
			user->addlevel();
		if (nxt->response() & StatusSlide::MENU)
		{
			active = false;
			return;
		}
		if (nxt->response() & StatusSlide::RESET)
		{
			rman->reset(suns);
			gman->reset();
			zman->reset(user->level());
		}
		
		for (auto it : teren)
			delete it;
		teren.clear();
		for (int i = 0; i < gman->terenY(); i++)
			for (int j = 0; j < TERENX; j++)
				teren.push_back(new ArenaButton(this, j, i));
	}

	Slide::clearZone(conOut);

	drawVline(conOut, VLINE);
	drawHline(conOut, HLINE);

	conOut(0, 2) << "~ STATUS PANEL ~";

	conOut(1, 2) << user->name();
	conOut(2, 2) << "Total score: ";

	conOut(3, 2) << "Level: ";
	conOut(4, 2) << "Score: ";

	conOut(3, 13) << "SUNS: ";
	conOut(4, 13) << "WAVE: ";

	for (auto it : menu)
		it->draw(conOut);
}

User* Arena::ArenaSlide::currentUser()
{
	return user;
}

UserInterface::ConsoleOutput Arena::ArenaSlide::console()
{
	return conOut;
}

bool Arena::ArenaSlide::responseSave()
{
	return saveuser;
}


ArenaSlide::~ArenaSlide()
{
	for (auto it : menu)
		delete it;
	for (auto it : teren)
		delete it;
	delete gman;
	delete zman;
}
