#pragma once
#include "Plant.h"
#include "ITimer.h"

namespace Arena {

	class CherryBomb :
		public BasicPlant,
		public ITimer
	{
	public:
		CherryBomb(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int x);

		virtual void update() override;
		virtual bool active() override;

		virtual void timerAction() override;
	};

}

