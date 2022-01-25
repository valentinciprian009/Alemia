#pragma once
#include "Plant.h"
#include "ITickable.h"

namespace Arena
{
	class PeaShooter :
		public BasicPlant,
		public ITickable
	{
	private:
		virtual void tickAction() override;
	
	public:
		PeaShooter(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x, bool frozen);

		virtual void update() override;
	};
}


