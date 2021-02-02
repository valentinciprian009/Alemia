#pragma once
#include "Zombie.h"

namespace Arena {

	class PoleZombie :
		public BasicZombie
	{
	protected:
		bool jumped;
		virtual void tickAction() override;
	public:
		PoleZombie(GameManager* pr, UserInterface::ConsoleOutput conout, int y, bool superzombie);
	};

}

