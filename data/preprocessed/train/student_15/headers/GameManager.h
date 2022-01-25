#pragma once
#include "ConsoleOutput.h"
#include <vector>
#include <fstream>

#include "Constants.h"

#include "Plant.h"
#include "PeaShooterPlant.h"
#include "Pea.h"
#include "Zombie.h"


namespace Arena
{
	class ArenaSlide;

	class GameManager
	{
	private:
		int tereny;
		BasicPlant* plants[TERENY][TERENX];
		std::vector<Pea*> peas[TERENY];
		std::vector<BasicZombie*> zombies[TERENY];

	private:
		int scr = 0;
		int wv = 0;
		ArenaSlide* parent;
		std::ofstream fout;

	public: 
		GameManager(ArenaSlide* pr);
		~GameManager();

		void reset();

		void addPlant(int id, int y, int x);
		void addZombie(int id, int y);
		bool empty(int y, int x);

		void update();
		void draw(UserInterface::ConsoleOutput conOut);

		void addScore(int inc);
		int score();
		int wave();

		void log(std::string s);
		void addToRate(int i);
		  
		void gameOver();

		bool nozombies();

		int terenY();

		friend class PeaShooter;
		friend class Pea;
		friend class CherryBomb;
		friend class PoleZombie;
		friend class BasicZombie;
	};
}

