#include "NormalZombie.h"
#include "PeaShooter.h"
#include "Pea.h"
#include <list>
#include <iostream>
#include <Windows.h>
#include "SnowPeaShooter.h"
#include "FrozenPea.h"

void main() {
	ConsoleHandler& myh = ConsoleHandler::getInstance();
	for (int i = 0; i < 103; i++)
	{
		myh(i, 2) << "_";
		myh(i, 7) << "_";
		myh(i, 12) << "_";
		myh(i, 17) << "_";
		myh(i, 22) << "_";
		myh(i, 27) << "_";
	}
	std::list<Entity*> plants;
	std::list<Entity*> bullets;
	std::list<Entity*> zombies;
	zombies.push_back(new NormalZombie(90, 5, zombies, plants));
	zombies.push_back(new NormalZombie(90, 10, zombies, plants));
	zombies.push_back(new NormalZombie(90, 15, zombies, plants));
	zombies.push_back(new NormalZombie(97, 20, zombies, plants));
	zombies.push_back(new NormalZombie(90, 25, zombies, plants));
	zombies.push_back(new NormalZombie(97, 25, zombies, plants));
	zombies.push_back(new NormalZombie(97, 15, zombies, plants));
	zombies.push_back(new NormalZombie(97, 5, zombies, plants));
	plants.push_back(new PeaShooter (8, 5, plants, bullets, zombies));
	plants.push_back(new PeaShooter(8, 10, plants, bullets, zombies));
	plants.push_back(new PeaShooter(8, 15, plants, bullets, zombies));
	plants.push_back(new PeaShooter(8, 20, plants, bullets, zombies));
	plants.push_back(new PeaShooter(8, 25, plants, bullets, zombies));
	std::list<Entity*>::iterator i;
	while (true)
	{
		for (auto j = plants.begin(); j != plants.end();)
		{
			i = j++;
			(*i)->update();
		}
		for (auto j = bullets.begin(); j != bullets.end();)
		{
			i = j++;
			(*i)->update();
		}
		for (auto j = zombies.begin(); j != zombies.end();)
		{
			i = j++;
			(*i)->update();
		}
		Sleep(100);
	}
	
}