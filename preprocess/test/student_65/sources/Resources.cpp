#include "Resources.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include "Sunn.h"
#include "Score.h"
using namespace std::chrono;
bool Resources::is_full()
{
	for (auto it : sun_list)
		if (it->is_full()==false)
			return true;
	return false;
}
void Resources::draw()
{
	for (auto it : sun_list)
		it->draw();
}

void Resources::update(std::string action)
{
	static auto begin = steady_clock::now();
	auto id = rand() % 5;
	 auto end = steady_clock::now();
	if (is_full() == true)
	{
		while (sun_list[id]->is_full() == true && is_full() == true)
		{
			id = rand() % 5;
		}
		if (duration_cast<seconds>(end - begin).count() > 10)
		{
			begin = end;
			Sunn* sun = new Sunn();
			sun_list[id]->set_entity(sun);
			sun_list[id]->set_filled();

		}
	}

	for (auto it : sun_list)
		if (it->is_full() == true && it->is_clicked(action) == true)
		{
			it->set_free();
			Score* score = Score::get_instance();
			score->update("5");
		}
}

Resources::~Resources()
{
}
