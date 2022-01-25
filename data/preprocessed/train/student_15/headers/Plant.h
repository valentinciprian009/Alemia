#pragma once
#include <string>
#include <array>
#include "IGameElement.h"
#include "PlantInfo.h"

namespace Arena
{
	class GameManager;

	class BasicPlant :
		public IGameElement
	{
	public:
		static const std::array<PlantInfo, 5> plants;
		
	protected:
		int id;
		int hp;
		int y, x;
		
	public:
		BasicPlant(GameManager* pr, UserInterface::ConsoleOutput conout, int plantID, int y, int x);
		~BasicPlant();

		int getID();
		void damage();

		void update() {};

		bool active();
		void draw();
	};

}
