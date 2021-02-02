#pragma once
#include "Slide.h"
#include "ConsoleOutput.h"
#include "ResourceManager.h"
#include "ArenaButtons.h"
#include "GameManager.h"
#include <vector>
#include "ZombieDispenser.h"
#include "User.h"

namespace Arena
{
	class ArenaSlide :
		public Slide
	{

	private:
		bool saveuser = false;

		User* user;

		std::vector<ArenaButton*> teren;
		std::vector<PlantButton*> menu;

		GameManager* gman;
		ResourceManager* rman;
		ZombieDispenser* zman;

		int suns = 0;
		int state = 0;

		void printNumber(int number, int y, int x);

	public:
		ArenaSlide(User* usr);
		~ArenaSlide();

		virtual void update() override;
		virtual void reinit() override;

		User* currentUser();

		UserInterface::ConsoleOutput console();

		bool responseSave();

		friend class ArenaButton;
		friend class PlantButton;
		friend class GameManager;
	};
}


