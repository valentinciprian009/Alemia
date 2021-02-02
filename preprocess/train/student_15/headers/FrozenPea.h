#pragma once
#include "Pea.h"

namespace Arena
{
	class FrozenPea :
		public Pea
	{
	protected:
		virtual void affectZombie(BasicZombie* z) override;

	public:
		FrozenPea(GameManager* pr, UserInterface::ConsoleOutput conout, int y0, int x0);
	};
}

