#include "Snow_Pea.h"
#include "Terrain.h"
void Snow_Pea::update(std::string)
{
	t.update();
	if (t.durata() > 5)
	{
		proiectile.push_back(new Frozen_Pea(this->get_x(), this->get_y() + 2,15));
		t.set_time();
		t.update();
	}
	for (auto it : proiectile)
	{
		if (it->get_y() == 103)
			proiectile.erase(proiectile.begin());
		it->update();
		for (auto i : Terrain::zombie)
		{
			if (i->get_x()-1 == (it->get_x()) && i->get_y() == it->get_y())
			{
				i->damaged(it->get_damage());
				proiectile.erase(proiectile.begin());
				delete it;
				break;
			}
		}
	}
}

Snow_Pea::~Snow_Pea()
{
}
