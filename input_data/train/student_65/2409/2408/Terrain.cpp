#include "Terrain.h"
#include "Shop.h"
#include "Zombie_banal.h"
std::vector<Zombie*> Terrain::zombie;
void Terrain::draw()
{
	for(int i=0;i<matrice.size();i++)
		for (auto it : matrice[i])
			it->draw();
	for (auto it : zombie)
		it->draw();
}

void Terrain::update(std::string action)
{
	for(int i=0;i<matrice.size();i++)
		for (auto it : matrice[i])
		{
			if (it->is_clicked(action))
			{
				if (Shop::buy) {
					if (Shop::buy()->get_name() == "Peashooter")
						it->set_entity(new Peashooter(0, 0));
					if (Shop::buy()->get_name() == "Snow_Pea")
						it->set_entity(new Snow_Pea(0, 0));
					if (Shop::buy()->get_name() == "Cherry_Bomb")
						it->set_entity(new Cherry_Bomb(0, 0));
					if (Shop::buy()->get_name() == "Wall_nut")
						it->set_entity(new Wall_nut(0, 0));
					if (Shop::buy()->get_name() == "Sunflower")
						it->set_entity(new Sunflower(0, 0));
				}
			}
			it->update(action);
		}
	create_zombie(action);
	for (auto i : zombie)
		i->update(action);
	for (int i=0;i<zombie.size();i++)
		if (zombie[i]->get_health() < 0)
		{
			zombie.erase(zombie.begin() + i);
			 delete zombie[i];
		}
}

void Terrain::create_zombie(std::string action)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	t.update();
	auto id = rand() % 5;
	if (t.durata() > 5)
	{

		zombie.push_back(new Zombie_banal(10 + id*6+2, 110));
		for (auto i : zombie)
			i->update(action);
		t.set_time();
		t.update();
	}

}



Terrain::~Terrain()
{
}
