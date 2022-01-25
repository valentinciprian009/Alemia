#pragma once
#include "Plant.h"

namespace Arena
{
	class SunflowerPlant :
		public BasicPlant
	{
	public:
		SunflowerPlant(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x);
		~SunflowerPlant();

		virtual void update() override;
	};
}


